// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBlueprintFunctionLibrary.h"


//void UMyBlueprintFunctionLibrary::MyMagicFunction(FString SomeString)
//{
//UE_LOG(LogTemp, Log, TEXT("DONE %s"), *SomeString);

//int32 UMyBlueprintFunctionLibrary::MyGetCustomPrimitiveData(const AActor* Actor)
//{
	// Your logic to get the custom primitive data.
	// For example, you could get the number of components the Actor has:
	//int32 ComponentCount = Actor->GetComponents().Num();
	//return ComponentCount;
//}


//float UMyBlueprintFunctionLibrary::GetCustomPrimitiveDataByIndex(UStaticMeshComponent* StaticMeshComponent, int32 Index, UPrimitiveComponent* Component, UActorComponent* Actor)

float UMyBlueprintFunctionLibrary::GetCustomPrimitiveDataByIndex(UStaticMeshComponent* StaticMeshComponent, UPrimitiveComponent* Component, int32 Index)
{
	if (StaticMeshComponent != nullptr)
	{
		//FVector Scale = StaticMeshComponent->GetComponentScale();
		FCustomPrimitiveData CPD = StaticMeshComponent->GetCustomPrimitiveData();

		if (CPD.Data.IsEmpty() == 0)
		{
			float DataByIndex = CPD.Data[Index];

			for (float DataValue : CPD.Data)
			{
				UE_LOG(LogTemp, Warning, TEXT("All CustomPrimitiveData values on mesh: %f"), DataValue);
			}

			return DataByIndex;
		}

		//UE_LOG(LogTemp, Warning, TEXT("Static Mesh Scale: (%f, %f, %f)"), Scale.X, Scale.Y, Scale.Z);

		//if (GEngine)
			//GEngine->AddOnScreenDebugMessage(-1, 8.0f, FColor::White, FString::Printf(TEXT("Well... %f, %f, %f"), Data0.X, Data0.Y, Data0.Z));
		
		// If no custom data provided
		return float(0.0);

	}

	if (Component != nullptr) 
	{
		FCustomPrimitiveData CPD = Component->GetCustomPrimitiveData();

		if (CPD.Data.IsEmpty() == 0)
		{
			float DataByIndex = CPD.Data[Index];

			for (float DataValue : CPD.Data)
			{
				UE_LOG(LogTemp, Warning, TEXT("All CustomPrimitiveData values on mesh: %f"), DataValue);
			}

			return DataByIndex;
		}
		// If no custom data provided
		return float(0.0);
	}
		// If function has no inputs
		return float(0.0);
}

FVector UMyBlueprintFunctionLibrary::SetMeshVertexColor(UStaticMesh* StaticMesh, FColor Color)
{
	//StaticMesh->SetVertexColorData(TMap < FVector3f, FColor(Color);

	return FVector();
}

float UMyBlueprintFunctionLibrary::GetInstanceCustomData(UInstancedStaticMeshComponent* InstancedStaticMeshComponent, int32 InstanceIndex)
{
	if (InstancedStaticMeshComponent->PerInstanceSMCustomData.Num() >= InstanceIndex) {
		
		return InstancedStaticMeshComponent->PerInstanceSMCustomData[InstanceIndex];
	}
	return 0;
}

UTextureCube* UMyBlueprintFunctionLibrary::ConstructTextureCube(UTextureRenderTargetCube* RenderTargetCube, FString NewName)
{
	if (RenderTargetCube == nullptr)
	{
		return nullptr;
	}

	enum EObjectFlags Flags 
	{
		RF_Public
		| RF_Standalone
		| RF_Transactional
		//| RF_NeedLoad
		| RF_KeepForCooker
		| RF_AllocatedInSharedPage
		//| RF_NeedPostLoadSubobjects
		//| RF_NeedPostLoad
		| RF_MarkAsNative
		//| RF_DefaultSubObject
		| RF_ArchetypeObject
		| RF_HasExternalPackage
	};

	// Create a new static texture cube
	//UTextureCube* TextureCube::CreateTransient(RenderTargetCube->SizeX, EPixelFormat::PF_B8G8R8A8);
	//UTextureCube* TextureCube = NewObject<UTextureCube>(GetTransientPackage(), FName("MyTextureCube"), RF_Public);

	// Construct the texture cube from the render target
	//RenderTargetCube->ConstructTextureCube(TextureCube);
	return (RenderTargetCube->ConstructTextureCube(RenderTargetCube, NewName, Flags));

	//return TextureCube;
}

bool UMyBlueprintFunctionLibrary::ExportTextureCube(UTextureCube* CubeTexture, FString FilePath)
{
	if (!CubeTexture) {
		return false;
	}

	//FArchive BufferArchive;
	//FString Result;

	// "Path/To/Export/File.hdr" // Output file path
	
	// Create an archive for the output file
	FArchive* FileArchive = IFileManager::Get().CreateFileWriter(*FilePath);

	// texture cube to array
	bool bSuccess = FImageUtils::ExportTextureCubeAsHDR(CubeTexture, *FileArchive);

	//FileArchive->Close();

	// If the export was successful, save the file path to a text file
	//if (bSuccess)
	//{
		//FString FileListPath = "F:/Unreal Engine Projects/Cpp_Functions_5_2/test export/FileList.txt"; // Path to the file list
		//FString FileListContent = FString::Printf(TEXT("%s\n"), *FilePath); // Append the file path to the file list
		//FFileHelper::SaveStringToFile(FileListContent, *FileListPath, FFileHelper::EEncodingOptions::ForceUTF8WithoutBOM);
	//}

	return bSuccess;

	// array to string
	//FFileHelper::LoadFileToString(Result, BufferArchive);

	// string to texture 2d
	//return (FImageUtils::ImportFileAsTexture2D(Result));

	//bool bExportSuccess = FFileHelper::SaveStringToFile(Result, *FilePath);


	//return (Result);


	//UImageWriteBlueprintLibrary::ExportToDisk(

	//UTextureCubeExporterHDR* ExporterHDR = NewObject<UTextureCubeExporterHDR>();
	//if (ExporterHDR->ExportToFile(CubeTexture, ExporterHDR, *FilePath, false, false, false) == 1) 

	//return bExportSuccess;
}

bool UMyBlueprintFunctionLibrary::ExportRenderTargetCube(UTextureRenderTargetCube* RenderTargetCube, FString FilePath)
{
	if (!RenderTargetCube) {
		return false;
	}

	FArchive* FileArchive = IFileManager::Get().CreateFileWriter(*FilePath);

	bool bSuccess = FImageUtils::ExportRenderTargetCubeAsHDR(RenderTargetCube, *FileArchive);
	
	FileArchive->Close();

	return bSuccess;
}

bool UMyBlueprintFunctionLibrary::SetNumCustomDataFloats(UHierarchicalInstancedStaticMeshComponent* HierarchicalInstance, int32 NumCustomDataFloats)
{
	if (HierarchicalInstance) {
		HierarchicalInstance->NumCustomDataFloats = NumCustomDataFloats; // Value >1 causes the crush (array out of bounds)
		return true;
	}
	return false;
}

bool UMyBlueprintFunctionLibrary::GetIsSpatiallyLoaded(AActor* Actor)
{
	return (Actor->GetIsSpatiallyLoaded());
}

void UMyBlueprintFunctionLibrary::SetIsSpatiallyLoaded(AActor* Actor, bool SetIsSpatiallyLoaded)
{
	Actor->SetIsSpatiallyLoaded(SetIsSpatiallyLoaded);
}

