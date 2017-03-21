// Fill out your copyright notice in the Description page of Project Settings.

#include "WebServeice.h"
#include "webConnect.h"

//DEFINE_LOG_CATEGORY(webConnect);

UwebConnect::UwebConnect()
{
	UE_LOG(LogClass, Warning, TEXT("%s"), TEXT("webConnect Constructor Call !"));
	Host = TEXT("localhost:8000");
	URI = TEXT("/");
}
void UwebConnect::RequestToken()
{
	UE_LOG(LogClass, Warning, TEXT("Request Token Call!"));
}
