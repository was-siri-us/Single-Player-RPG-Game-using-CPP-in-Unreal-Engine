// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "GoldCoin.generated.h"

/**
 *
 */
UCLASS()
class FINAL_API AGoldCoin : public AItem
{
	GENERATED_BODY()
public:
	AGoldCoin();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category =
		"CoinValue")
		int32 GoldCoinValue;

	virtual void OnOverlapBegin(UPrimitiveComponent*
		OverlappedComponent, AActor* OtherActor, UPrimitiveComponent*
		OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
		FHitResult& SweepResult) override;

};
