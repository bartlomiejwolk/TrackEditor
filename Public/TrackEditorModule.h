#pragma once
 
#include "Engine.h"
 
DECLARE_LOG_CATEGORY_EXTERN(TrackEditorModule, All, All)
 
class FTrackEditorModule : public IModuleInterface
{
public:
	void StartupModule() override;
	void ShutdownModule() override;
 
};