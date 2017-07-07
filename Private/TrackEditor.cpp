/*
Copyright 2016-2017 Bartlomiej Wolk (metroidsnes)
Licensed under MIT license. See the LICENSE file in the module root folder.
*/

#include "Public/TrackEditorModule.h"
#include "TrackEditor.h"
#include "Components/SplineMeshComponent.h"

// Sets default values
ATrackEditor::ATrackEditor()
{
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline"));
	// todo doesn't have any effect
	SplineComponent->SetClosedLoop(false);
	SetRootComponent(SplineComponent);
}

void ATrackEditor::OnConstruction(const FTransform& Transform)
{
	// Calculate number of sections
	int32 sectionsCount = 0;
	{
		int32 splinePointsCount = SplineComponent->GetNumberOfSplinePoints();
		bool loopClosed = SplineComponent->IsClosedLoop();
		sectionsCount = loopClosed ? splinePointsCount : splinePointsCount - 1;
	}

	// Construct track
	for (int32 i = 0; i < sectionsCount; i++)
	{
		CreateTrackElement(TrackPieceMesh, i);
		CreateTrackElement(LeftGuardRailMesh, i);
		CreateTrackElement(RightGuardRailMesh, i);
	}
}

void ATrackEditor::CreateTrackElement(UStaticMesh* trackElement, const int splinePointIndex)
{
	if (trackElement == nullptr)
	{
		return;
	}
	
	int32 splinePointsCount = SplineComponent->GetNumberOfSplinePoints();
	int32 nextSplinePointIndex = (splinePointIndex + 1) % splinePointsCount;

	// Create mesh component name
	FName name;
	{
		FString temp;
		temp.Append(trackElement->GetName());
		temp.Append(FString::FromInt(splinePointIndex));
		name = std::move<FName>(FName(temp.GetCharArray().GetData()));
	}

	// Instantiate spline mesh
	USplineMeshComponent* splineMeshComponent = NewObject<USplineMeshComponent>(this, name);
	{
		splineMeshComponent->CreationMethod = EComponentCreationMethod::UserConstructionScript;
		splineMeshComponent->SetMobility(EComponentMobility::Static);
		splineMeshComponent->RegisterComponent();
		splineMeshComponent->SetStaticMesh(trackElement);
		splineMeshComponent->AttachToComponent(GetRootComponent(), FAttachmentTransformRules::KeepRelativeTransform);	
	}

	// Place spline mesh along spline
	{
		FVector startLocation;
		FVector endLocation;
		FVector startTangent;
		FVector endTangent;
		SplineComponent->GetLocalLocationAndTangentAtSplinePoint(splinePointIndex, startLocation, startTangent);
		SplineComponent->GetLocalLocationAndTangentAtSplinePoint(nextSplinePointIndex, endLocation, endTangent);
		splineMeshComponent->SetStartAndEnd(startLocation, startTangent, endLocation, endTangent);
	}

	// Set spline mesh rotation
	{
		float startRoll = SplineComponent->GetRollAtSplinePoint(splinePointIndex, ESplineCoordinateSpace::Local);
		float endRoll = SplineComponent->GetRollAtSplinePoint(nextSplinePointIndex, ESplineCoordinateSpace::Local);
		startRoll *= RotationHandleSensitivity;
		endRoll *= RotationHandleSensitivity;
		splineMeshComponent->SetStartRoll(startRoll);
		splineMeshComponent->SetEndRoll(endRoll);	
	}
	
	// Set spline mesh scale
	{
		FVector startScale = SplineComponent->GetScaleAtSplinePoint(splinePointIndex);
		FVector2D startScale2d = FVector2D(startScale.Y, startScale.Z);
		FVector EndScale = SplineComponent->GetScaleAtSplinePoint(nextSplinePointIndex);
		FVector2D endScale2d = FVector2D(EndScale.Y, EndScale.Z);
		splineMeshComponent->SetStartScale(startScale2d);
		splineMeshComponent->SetEndScale(endScale2d);
	}

	// Set spline mesh collision type
	splineMeshComponent->SetCollisionEnabled(CollisionType);
}

// Called when the game starts or when spawned
void ATrackEditor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATrackEditor::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

