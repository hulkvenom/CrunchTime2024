// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "AbilitySystemInterface.h"
#include "GameFramework/Character.h"
#include "GameplayEffectTypes.h"

#include "CCharacterBase.generated.h"

class UCAbilitySystemComponent;
class UCAttributeSet;

UCLASS()
class ACCharacterBase : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ACCharacterBase();
	void SetupAbilitySystemComponent();
	void InitAbilityAndAttributes();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/*************************************************************/
	/*                              Gameplay Ability                                  */
	/*************************************************************/
public:
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	void InitStatusHUD();
private:
	UPROPERTY(VisibleAnywhere, Category = "Gameplay Ability")
	UCAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY()
	UCAttributeSet* AttributeSet;

	UPROPERTY(VisibleAnywhere, Category = "UI")
	class UWidgetComponent* StatusWidgetComp;

	UPROPERTY()
	class UStatusGuage* StatusGuage;

	void HealthUpdated(const FOnAttributeChangeData& ChangeData);
	void MaxHealthUpdated(const FOnAttributeChangeData& ChangeData);
};
