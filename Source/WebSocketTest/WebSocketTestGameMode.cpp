// Copyright Epic Games, Inc. All Rights Reserved.

#include "WebSocketTestGameMode.h"
#include "WebSocketTestCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWebSocketTestGameMode::AWebSocketTestGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
