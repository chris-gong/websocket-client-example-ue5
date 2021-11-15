// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "IWebSocket.h"
#include "WebSocketTestGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class WEBSOCKETTEST_API UWebSocketTestGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	virtual void Init() override;
	virtual void Shutdown() override;

	TSharedPtr<IWebSocket> WebSocket;
	
};
