// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorSetMaxFPS.h"

#include "Editor.h"

#define LOCTEXT_NAMESPACE "FEditorSetMaxFPSModule"

void FEditorSetMaxFPSModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	if (ensure(GEngine))
	{
		if (ensure(GEditor))
		{
			UWorld* World = GEditor->EditorWorld;
			ensure(GEngine->Exec(World, TEXT("t.maxfps 60")));
		}
	}
}

void FEditorSetMaxFPSModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEditorSetMaxFPSModule, EditorSetMaxFPS)