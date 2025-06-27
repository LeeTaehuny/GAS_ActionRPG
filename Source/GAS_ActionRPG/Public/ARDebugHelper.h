#pragma once

namespace Debug
{
	static void Print(const FString& Msg, const FColor& Color = FColor::MakeRandomColor(), int32 InKey = -1, int32 InTime = 7.0f)
	{
		if (GEngine)
		{
			GEngine->AddOnScreenDebugMessage(InKey, InTime, Color, Msg);
			UE_LOG(LogTemp, Warning, TEXT("%s"), *Msg);
		}
	}
}