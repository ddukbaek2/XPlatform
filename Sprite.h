#pragma once

#include "XPlatform.h"
#include "Object.h"
#include "IGL.h"
#include "Texture.h"
#include "Material.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 스프라이트.
	/////////////////////////////////////////////////////////////////////////////
	class Sprite : public Object
	{
	private:
		typedef Object Base;

	protected:
		Ref<Texture> m_Texture;

	protected:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;

	public:
		void SetTexture(Ref<Texture> texture);
		void SetMaterial(Ref<Material> material);
		void Render(Ref<IGL> gl);
	};
}
