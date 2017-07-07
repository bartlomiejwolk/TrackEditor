// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class TrackEditorModule : ModuleRules
{
	public TrackEditorModule(ReadOnlyTargetRules Target) : base(Target)
	{
		MinFilesUsingPrecompiledHeaderOverride = 1;
        bFasterWithoutUnity = true;
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
		PrivateDependencyModuleNames.AddRange(new string[] {  });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true

        PublicIncludePaths.AddRange(new string[] { "TrackEditorModule/Public" });
        PrivateIncludePaths.AddRange(new string[] { "TrackEditorModule/Private" });

    }
}
