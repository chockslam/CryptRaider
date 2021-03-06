// Fill out your copyright notice in the Description page of Project Settings.

#pragma once



#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "PhysicsEngine/PhysicsHandleComponent.h"
#include "Grabber.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CRYPTRAIDER_API UGrabber : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Do upon release.
	UFUNCTION(BlueprintCallable)
	void Release();
	
	// Perform while grabbed.
	UFUNCTION(BlueprintCallable)
	void Grab();

		
private:
	// Denotes the distance maximum distance where object can be grabbed.
	UPROPERTY(EditAnywhere)
	float MaxGrabDistance;

	// Denotes the radius of the collision shape.
	UPROPERTY(EditAnywhere)
	float GrabRadius;


	// How far awway object can be from this component's origin.
	UPROPERTY(EditAnywhere)
	float HoldDistance;

	// Return a pointer to physics components.
	UPhysicsHandleComponent* GetPhysicsHandle() const;

	// Output whether the object has been hit (bool) and hitResult.
	void GetGrabbableInReach(bool& hasHit, FHitResult& hitResult) const;
	
};
