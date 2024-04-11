// Fill out your copyright notice in the Description page of Project Settings.


#include "SilverCoin.h"
#include "AuroraCharacter.h"

ASilverCoin::ASilverCoin() {
	SilverCoinValue = 1;
}


void ASilverCoin::OnOverlapBegin(UPrimitiveComponent*
	OverlappedComponent, AActor* OtherActor, UPrimitiveComponent*
	OtherComp, int32 OtherBodyIndex, bool bFromSweep, const
	FHitResult& SweepResult) {

	AAuroraCharacter* AuroraCharacter = Cast<AAuroraCharacter>(OtherActor);

	if (AuroraCharacter) {
		AuroraCharacter->SetSilverCoins(AuroraCharacter->GetSilverCoins() + SilverCoinValue);
		Destroy();
	}
	Super::OnOverlapBegin(OverlappedComponent, OtherActor,
		OtherComp, OtherBodyIndex, bFromSweep, SweepResult);
}
