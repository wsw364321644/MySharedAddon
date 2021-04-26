// © Rollingmedia 2016 all rights reserved
#include "MySharedAddonPlugin.h"
#include "MySharedAddonPluginPrivatePCH.h"
#include"Interfaces\IPluginManager.h"
#include "GeometrySystem.h"

IMPLEMENT_MODULE(FMySharedAddonPlugin, MySharedAddon)



void FMySharedAddonPlugin::StartupModule()
{
	// Explicitly load the plugin DLL from the plugin directory to save copying it into the binaries directory when packaging.
	//FString path = IPluginManager::Get().FindPlugin("MySharedAddon")->GetBaseDir() + TEXT("\\") + (OPENMESH_DLL_PATH) + "\\" + TEXT("OpenMeshCore.dll");
	//m_OpenMeshCoreHandle = FPlatformProcess::GetDllHandle(*path);
	//check(m_OpenMeshCoreHandle);

	//path = IPluginManager::Get().FindPlugin("MySharedAddon")->GetBaseDir() + TEXT("\\") + (OPENMESH_DLL_PATH)+"\\" + TEXT("OpenMeshTools.dll");
	//m_OpenMeshToolsHandle = FPlatformProcess::GetDllHandle(*path);
	//check(m_OpenMeshToolsHandle);



	m_geometrySystem = MakeShareable(new FGeometrySystem());
}


void FMySharedAddonPlugin::ShutdownModule()
{
	/*FPlatformProcess::FreeDllHandle(m_OpenMeshCoreHandle);
	FPlatformProcess::FreeDllHandle(m_OpenMeshToolsHandle);*/
}

FMySharedAddonPlugin* FMySharedAddonPlugin::Get()
{
	static const FName ModuleName = TEXT("MySharedAddon");
	FMySharedAddonPlugin* OSSModule = FModuleManager::GetModulePtr<FMySharedAddonPlugin>(ModuleName);
	return OSSModule;
}