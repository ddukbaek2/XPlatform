﻿#pragma once

#include "XPlatform.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 2차원 벡터.
	/////////////////////////////////////////////////////////////////////////////
	struct Vector2
	{
		union
		{
			struct
			{
				float X;
				float Y;
			};

			float Array[2];
		};

		Vector2()
		{
			X = Y =  0.0f;
		}

		Vector2(float x, float y)
		{
			X = x;
			Y = y;
		}
	};
}
