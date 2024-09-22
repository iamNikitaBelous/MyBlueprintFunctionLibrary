// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Components/InstancedStaticMeshComponent.h" // to get per instance custom data
#include "Components/HierarchicalInstancedStaticMeshComponent.h"
#include "Engine/TextureRenderTargetCube.h" // convert render target cube to texture cube
//#include "Engine/TextureCube.h" // to export texture cube
//#include "Exporters/TextureCubeExporterHDR.h" //(UnrealEd module) to export texture cube 
#include "ImageUtils.h" // to save texture cube in data archive
#include "Misc/FileHelper.h" // to export data archive

#include "MyBlueprintFunctionLibrary.generated.h"


/**
 * 
 */
UCLASS()
class CPP_FUNCTIONS_5_2_API UMyBlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

		//UFUNCTION(BlueprintCallable, Category = "MyTest")
		//static void MyMagicFunction(FString SomeString);

		//UFUNCTION(BlueprintCallable, Category = "MyTest")
		//static int32 MyGetCustomPrimitiveData(const AActor* Actor);

	public:
		UFUNCTION(BlueprintCallable, Category = "Custom Functions")
		static float GetCustomPrimitiveDataByIndex(UStaticMeshComponent* StaticMeshComponent, UPrimitiveComponent* Component, int32 Index);

		UFUNCTION(BlueprintCallable, Category = "Custom Functions")
		static FVector SetMeshVertexColor(UStaticMesh* StaticMesh, FColor Color);

		UFUNCTION(BlueprintPure, Category = "Custom Functions")
		static float GetInstanceCustomData(UInstancedStaticMeshComponent* InstancedStaticMeshComponent, int32 InstanceIndex);

		UFUNCTION(BlueprintCallable, Category = "Custom Functions")
		static UTextureCube* ConstructTextureCube(UTextureRenderTargetCube* RenderTargetCube, FString NewName);

		UFUNCTION(BlueprintCallable, Category = "MyBlueprintFunctionLibrary")
		static bool ExportTextureCube(UTextureCube* CubeTexture, FString FilePath);

		UFUNCTION(BlueprintCallable, Category = "MyBlueprintFunctionLibrary")
		static bool ExportRenderTargetCube(UTextureRenderTargetCube* RenderTargetCube, FString FilePath);

		UFUNCTION(BlueprintCallable, Category = "MyBlueprintFunctionLibrary")
		static bool SetNumCustomDataFloats(UHierarchicalInstancedStaticMeshComponent* HierarchicalInstance, int32 NumCustomDataFloats);

		UFUNCTION(BlueprintCallable, Category = "MyBlueprintFunctionLibrary")
		static bool GetIsSpatiallyLoaded(AActor* Actor);
		
		UFUNCTION(BlueprintCallable, Category = "MyBlueprintFunctionLibrary")
		static void SetIsSpatiallyLoaded(AActor* Actor, bool SetIsSpatiallyLoaded);


};
