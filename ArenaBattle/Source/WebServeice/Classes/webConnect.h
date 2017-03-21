// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "UObject/NoExportTypes.h"
#include "webConnect.generated.h"

/**
 * 
 */
UCLASS()
class WEBSERVEICE_API UwebConnect : public UObject
{
	GENERATED_BODY()

public:
	UwebConnect();

	//UPROPERTY() // Ŭ���� ������ �����Ҷ��� �� ����ϱ�
	//FString MyName;
	//UFUNCTION()
	//FString GetName() { return TEXT("MyName"); }
	
	
	UPROPERTY()
		FString Host;

	UPROPERTY()
		FString URI;

	UFUNCTION()
		void RequestToken();
	
};

//DECLARE_LOG_CATEGORY_EXTERN(WebConnection, Log, All);