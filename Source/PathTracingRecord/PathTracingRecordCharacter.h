// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PathTracingRecordCharacter.generated.h"

UCLASS(config=Game)
class APathTracingRecordCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

public:
	APathTracingRecordCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;


	UFUNCTION(BlueprintCallable)
		FVector GetCameraLocation();

	UFUNCTION(BlueprintCallable)
		FRotator GetCameraRotation();

protected:
	

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);
protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	
	

private:

	UPROPERTY(Replicated)
		FVector m_replicatedCameraWorldLocation;
	UPROPERTY(Replicated)
		FRotator m_replicatedCameraWorldRotation;

	UFUNCTION(BlueprintCallable,NetMulticast,Reliable)
		void MulticastUpdate();//replicate데이터를 업데이트
	UFUNCTION(BlueprintCallable)
		void UpdateReplayCamera(float deltaTime,APlayerController* playerController);//spectator pawn카메라를 기록된 카메라 transform으로 업데이트
	
	

	void MulticastUpdate_Implementation();

private:
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;//replicate된 변수등록절차

};

