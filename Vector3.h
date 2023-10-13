#pragma once
#include "XPlatform.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 3차원 벡터.
	/////////////////////////////////////////////////////////////////////////////
	struct Vector3
	{
		union
		{
			struct
			{
				float X;
				float Y;
				float Z;
			};

			float Array[3];
		};

		Vector3()
		{
			X = Y = Z = 0.0f;
		}

		Vector3(float x, float y, float z)
		{
			X = x;
			Y = y;
			Z = z;
		}
	};
}