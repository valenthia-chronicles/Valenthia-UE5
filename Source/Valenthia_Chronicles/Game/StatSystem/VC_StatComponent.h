// MIT License - Copyright (c) 2024 Valenthia Chronicles

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VC_StatComponent.generated.h"


UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class VALENTHIA_CHRONICLES_API UVC_StatComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UVC_StatComponent();

	// Health functions
	UFUNCTION(BlueprintCallable)
	int32 GetCurrentHealth() const {return Health;};
	UFUNCTION(BlueprintCallable)
	int32 GetMaxHealth() const {return MaxHealth;}
	UFUNCTION(BlueprintCallable)
	void UpdateCurrentHealth(const int32 Amount);
	
	// Power functions
	UFUNCTION(BlueprintCallable)
	int32 GetCurrentPower() const {return Power;}
	UFUNCTION(BlueprintCallable)
	int32 GetMaxPower() const {return MaxPower;}
	UFUNCTION(BlueprintCallable)
	void UpdateCurrentPower(const int32 Amount);
	
	// Level functions
	UFUNCTION(BlueprintCallable)
	uint8 GetLevel() const {return Level;}
	UFUNCTION(BlueprintCallable)
	void SetLevel(const uint8 NewLevel);

	// Stats variables
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UnitStats")
	int32 Health;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UnitStats")
	int32 MaxHealth;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UnitStats")
	int32 Power;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "UnitStats")
	int32 MaxPower;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "UnitStats")
	uint8 Level;
	
protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
