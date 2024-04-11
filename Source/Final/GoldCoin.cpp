// Fill out your copyright notice in the Description page of Project Settings.


#include "GoldCoin.h"
#include "AuroraCharacter.h"

AGoldCoin::AGoldCoin() {
	GoldCoinValue = 1;
}


void AGoldCoin::OnOverlapBegin(UPrimitiveComponent*
	OverlappedComponent, AActor* OtherActor, UPrimitiveComponent*
	OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
	FHitResult& SweepResult) {

	AAuroraCharacter* AuroraCharacter = Cast<AAuroraCharacter>(OtherActor);

	if (AuroraCharacter) {
		AuroraCharacter->SetGoldCoins(AuroraCharacter->GetGoldCoins() + GoldCoinValue);
		Destroy();
	}
	Super::OnOverlapBegin(OverlappedComponent, OtherActor,
		OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}



