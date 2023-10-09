#pragma once
#include "XPlatform.h"
#include "Vector2.h"
#include "Vector3.h"


namespace XPlatform
{
	struct Vertex
	{
		Vector3 Position;
		Vector3 Normal;
		Vector2 TextureCoord;
	};
}
