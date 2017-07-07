/*
Copyright 2016-2017 Bartlomiej Wolk (metroidsnes)
Licensed under MIT license. See the LICENSE file in the module root folder.
*/

#pragma once

#include "GameFramework/Actor.h"
#include "Runtime/Engine/Classes/Components/SplineComponent.h"
#include "Components/SplineMeshComponent.h"
#include "TrackEditor.generated.h"

/*
Place this actor in the scene in order to dynamically create drivable tracks.
Set properties in the details view.
*/
UCLASS()
class ATrackEditor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATrackEditor();

	void BeginPlay() override;
	
	void Tick( float DeltaSeconds ) override;

	/*
	Called every time the Actor is updated from the editor,
	e.g. when you move spline point on the scene.
	You may need to create a blueprint that inherits from this class in order
	for this to be called properly.
	*/
	void OnConstruction(const FTransform& Transform) override;

private:
	/*
	Used to decrease sensitiviy of the spline point rotation handle.
	*/
	const float RotationHandleSensitivity = 0.01f;

	/*
	Spline component used to define track shape in the editor.
	Created in the constructor.
	*/
	UPROPERTY(VisibleAnywhere)
	class USplineComponent* SplineComponent;
	
	/*
	Mesh used to construct the surface of the track.
	*/
	UPROPERTY(EditAnywhere, Category="Custom")
	class UStaticMesh* TrackPieceMesh;

	/*
	Mesh used to construct the track left guard rail.
	*/
	UPROPERTY(EditAnywhere, Category="Custom")
	class UStaticMesh* LeftGuardRailMesh;
	
	/*
	Mesh used to construct the track right guard rail.
	*/
	UPROPERTY(EditAnywhere, Category="Custom")
	class UStaticMesh* RightGuardRailMesh;

	/*
	Sets collision type of track meshes.
	Check `ECollisionEnabled::Type` for possible options.
	*/
	UPROPERTY(EditAnywhere, Category="Custom")
	TEnumAsByte<ECollisionEnabled::Type> CollisionType;

	/*
	Instantiates and positions single mesh at a spline point.
	trackElement Mesh to be instantiated.
	splinePointIndex Spline point where the mesh will be positioned.
	*/
	void CreateTrackElement(UStaticMesh* trackElement, const int splinePointIndex);

};
