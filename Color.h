#pragma once
#include "XPlatform.h"


namespace XPlatform
{
	union Color
	{
		struct
		{
			uint8_t R;
			uint8_t G;
			uint8_t B;
			uint8_t A;
		};

		uint8_t Array[4];

		Color()
		{
			R = G = B = A = 0.0f;
		}

		Color(float r, float g, float b, float a)
		{
			R = r / 255.0f;
			G = g / 255.0f;
			B = b / 255.0f;
			A = a / 255.0f;
		}
	};
}