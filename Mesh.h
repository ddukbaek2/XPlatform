#pragma once
#include "Vertex.h"


namespace XPlatform
{
	class Mesh
	{
	private:
		std::vector<Vertex> m_Vertices;
		std::vector<unsigned short> m_Indices;

	public:
		Mesh();
		virtual ~Mesh();
	};
}