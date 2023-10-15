#pragma once

#include "XPlatform.h"
#include "IGL.h"
#include "IDrawable.h"
#include "Object.h"
#include "Shader.h"
#include "Texture.h"
#include "Material.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 배치 스프라이트.
	/////////////////////////////////////////////////////////////////////////////
	class BatchSprite : public Object, public IDrawable
	{
	private:
		typedef Object Base;

	protected:
		//std::vector<
		Ref<Material> m_Material;

	protected:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;

	public:
		void SetMaterial(Ref<Material> material);
		//void SetTransform();
		//void clear();
		//void add();
		//void insert();
		//void remove();

		void Render(Ref<IGL> gl);
	};
}
