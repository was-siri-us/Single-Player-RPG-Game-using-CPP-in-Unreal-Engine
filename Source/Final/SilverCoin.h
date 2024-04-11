// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "SilverCoin.generated.h"

/**
 *
 */
UCLASS()
class FINAL_API ASilverCoin : public AItem
{
	GENERATED_BODY()
public:
	ASilverCoin();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =
		"CoinValue")
		int32 SilverCoinValue;
	virtual void OnOverlapBegin(UPrimitiveComponent*
		OverlappedComponent, AActor* OtherActor, UPrimitiveComponent*
		OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
		FHitResult& SweepResult) override;

};
