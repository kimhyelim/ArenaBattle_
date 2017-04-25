// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/GameInstance.h"
#include "WebConnection.h" 
#include "ABGameInstance.generated.h"

class FHouse
{
public:
	TSharedPtr<FHouse> OthersDeed;
	TWeakPtr<FHouse> AccessHouse;
	int32 Size = 10;

	void RequestTokenComplete(const FString& token) 
	{
		UE_LOG(LogClass, Warning, TEXT("Test..."));
	}
};
/**
 * 
 */
UCLASS()
class ARENABATTLE_API UABGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UABGameInstance();

	virtual void Init() override;


	UPROPERTY()
		class UWebConnection* WebConnect;

	class UWebConnection* WebConnectionNew;

	//UPROPERTY()
		class UWebConnection* WebConnect2;

	UPROPERTY()
		FStreamableManager AssetLoader;

	

	FTimerHandle ObjectCheckTimer;

	UFUNCTION()
		void CheckUObjectAlive();

	UFUNCTION()
		void RequestTokenComplete(const FString& Token);
	UFUNCTION()
		void RequestTokenComplete2(const FString& Token);

};