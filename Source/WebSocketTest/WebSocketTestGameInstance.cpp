// Fill out your copyright notice in the Description page of Project Settings.


#include "WebSocketTestGameInstance.h"
#include "WebSocketsModule.h"

void UWebSocketTestGameInstance::Init()
{
	Super::Init();

	if (!FModuleManager::Get().IsModuleLoaded("WebSockets"))
	{
		FModuleManager::Get().LoadModule("WebSockets");
	}

	WebSocket = FWebSocketsModule::Get().CreateWebSocket("ws://localhost:8080");

	WebSocket->OnConnected().AddLambda([]()
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Green, "Successfully connected");
	});

	WebSocket->OnConnectionError().AddLambda([](const FString& Error)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Red, Error);
	});

	WebSocket->OnClosed().AddLambda([](int32 StatusCode, const FString& Reason, bool bWasClean)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, bWasClean ? FColor::Green : FColor::Red, "Connection closed " + Reason);
	});

	WebSocket->OnMessage().AddLambda([](const FString& MessageString)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Cyan, "Received message: " + MessageString);
	});

	WebSocket->OnMessageSent().AddLambda([](const FString& MessageString)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Sent message: " + MessageString);
	});

	WebSocket->Connect();
}

void UWebSocketTestGameInstance::Shutdown()
{
	if (WebSocket->IsConnected())
	{
		WebSocket->Close();
	}
	Super::Shutdown();
}
