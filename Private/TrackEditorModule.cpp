#include "TrackEditorModule.h"

IMPLEMENT_GAME_MODULE(FTrackEditorModule, TrackEditorModule);

DEFINE_LOG_CATEGORY(TrackEditorModule)
 
#define LOCTEXT_NAMESPACE "TrackEditor"
 
void FTrackEditorModule::StartupModule()
{
	UE_LOG(TrackEditorModule, Log, TEXT("Module loaded!"));
}
 
void FTrackEditorModule::ShutdownModule()
{
	UE_LOG(TrackEditorModule, Log, TEXT("Module unloaded"));
}
 
#undef LOCTEXT_NAMESPACE