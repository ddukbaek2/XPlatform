#pragma once
#include "Vertex.h"


namespace XPlatform
{
	class Mesh
	{
	private:
		std::vector<Vertex> m_Vertices;
		std::vector<uint32_t> m_Indices;
		std::vector<Vector2> m_TextureCoords;

	public:
		Mesh();
		virtual ~Mesh();
	};
}