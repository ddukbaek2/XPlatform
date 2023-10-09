#pragma once

#include "IDrawable.h"
#include "Vertex.h"


namespace XPlatform
{
	class SubMesh
	{

	};

	class Mesh : public IDrawable
	{
	protected:
		// 서브메쉬.
		std::vector<Mesh> m_SubMeshes;

		// 지오메트리.
		std::vector<Vertex> m_Vertices;
		std::vector<uint32_t> m_Indices;
		uint32_t m_TextureID;
		uint32_t m_MaterialID;

		// UV.
		std::vector<Vector2> m_TextureCoords;

	public:
		Mesh();
		virtual ~Mesh();
	};
}
