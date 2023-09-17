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

	union Vector3f
	{
		struct
		{
			float X;
			float Y;
			float Z;
		};

		float Value[3];
	};

	struct Vertex
	{
		Vector3f Position;
		Vector2f UV;
	};

	class Mesh
	{
	private:
		std::vector<Vertex> vertices;
		std::vector<unsigned short> indices;

	public:
	};

	struct Material
	{
	};
}