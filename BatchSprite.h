#pragma once

#include "XPlatform.h"
#include "IGL.h"
#include "Object.h"
#include "Texture.h"
#include "Material.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 배치 스프라이트.
	/////////////////////////////////////////////////////////////////////////////
	class BatchSprite : public Object
	{
	private:
		typedef Object Base;

	protected:
		Ref<Texture> m_Texture;

	public:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;

		void SetTexture(Ref<Texture> texture);
		void SetMaterial(Ref<Material> material);
		void Render(Ref<IGL> gl);
	};
}
