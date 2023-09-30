#pragma once
#include "XPlatform.h"


namespace XPlatform
{
	union Color
	{
		struct
		{
			float R;
			float G;
			float B;
			float A;
		};

		float Array[4];

		Color()
		{
			R = G = B = A = 0.0f;
		}

		Color(float r, float g, float b, float a)
		{
			R = r;
			G = g;
			B = b;
			A = a;
		}

		Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
		{
			R = r / 255.0f;
			G = g / 255.0f;
			B = b / 255.0f;
			A = a / 255.0f;
		}
	};
}
