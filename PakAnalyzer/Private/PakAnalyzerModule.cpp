// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PakAnalyzerModule.h"
#include "Modules/ModuleManager.h"

#include "CommonDefines.h"
#include "PakAnalyzer.h"

DEFINE_LOG_CATEGORY(LogPakAnalyzer);

FOnGetAESKey FPakAnalyzerDelegates::OnGetAESKey;
FOnLoadPakFailed FPakAnalyzerDelegates::OnLoadPakFailed;

class FPakAnalyzerModule : public IPakAnalyzerModule
{
public:
	// Begin IModuleInterface
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	virtual TSharedPtr<IPakAnalyzer> GetPakAnalyzer() override;

protected:
	TSharedPtr<FPakAnalyzer> AnalyzerInstance;
};

IMPLEMENT_MODULE(FPakAnalyzerModule, PakAnalyzer);

void FPakAnalyzerModule::StartupModule()
{
	AnalyzerInstance = MakeShared<FPakAnalyzer>();
}

void FPakAnalyzerModule::ShutdownModule()
{
	AnalyzerInstance.Reset();
}

TSharedPtr<IPakAnalyzer> FPakAnalyzerModule::GetPakAnalyzer()
{
	return AnalyzerInstance;
}
