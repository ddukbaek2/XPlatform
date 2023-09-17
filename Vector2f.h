#pragma once
#include "XPlatform.h"


namespace XPlatform
{
	union Vector2f
	{
		struct
		{
			float X;
			float Y;
		};

		struct
		{
			float U;
			float V;
		};

		float Value[2];
	};
}