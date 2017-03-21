// Fill out your copyright notice in the Description page of Project Settings.

#include "ArenaBattle.h"
#include "ABGameInstance.h"


UABGameInstance::UABGameInstance()
{
	//UE_LOG(LogClass, Warning, TEXT("%s"), TEXT("UABGameInstance Constructor !"));
	AB_LOG(Warning,TEXT("%s"), TEXT("UABGameInstance Constructor !"));
	WebConnect = CreateDefaultSubobject<UwebConnect>(TEXT("WebConnect"));
}

void UABGameInstance::Init()
{
	Super::Init();
	AB_LOG_CALLONLY(Warning);
	WebConnect2 = NewObject<UwebConnect>(this);
	//UE_LOG(LogClass, Warning, TEXT("%s"), TEXT("UABGameInstance Init !"));
	UClass* ClassInfo1 = WebConnect->GetClass();
	UClass* ClassInfo2 =UwebConnect::StaticClass();
	if (ClassInfo1 == ClassInfo2)
	{
		AB_LOG(Warning, TEXT("%s"), TEXT("ClassInfo1 is same with ClassInfo2 !"));
	}
	for (TFieldIterator<UProperty> It(ClassInfo1); It; ++It)
	{
		AB_LOG(Warning, TEXT("Field : %s, Type : %s"), *It->GetName(), *It->GetClass()->GetName());
		UStrProperty* StrProp = FindField<UStrProperty>(ClassInfo1, *It->GetName());
		if (StrProp)
		{
			AB_LOG(Warning, TEXT("Value = %s"), *StrProp->GetPropertyValue_InContainer(WebConnect));
		}
	}


	for (const auto& Entry : ClassInfo1->NativeFunctionLookupTable)
	{
		AB_LOG(Warning, TEXT("Function = %s"), *Entry.Name.ToString());
		UFunction* Func1 = ClassInfo1->FindFunctionByName(Entry.Name);
		if (Func1->ParmsSize == 0)
		{
			WebConnect->ProcessEvent(Func1, NULL);
		}
	}
}

