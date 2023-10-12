#pragma once

#include "XPlatform.h"
#include "Object.h"
#include "IDrawable.h"
#include "Vertex.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 메쉬.
	/////////////////////////////////////////////////////////////////////////////
	class Mesh : public Object, public IDrawable
	{
	private:
		typedef Object Base;

	public:
		struct Data
		{
			// 지오메트리.
			std::vector<Vertex> Vertices;
			std::vector<uint32_t> Indices;

			// 텍스쳐.
			uint32_t TextureID;

			// 머터리얼.
			uint32_t MaterialID;
		};

	protected:
		// 서브메쉬.
		std::vector<Data> m_SubMeshes;
		Data m_MainMesh;

	protected:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;
	};
}