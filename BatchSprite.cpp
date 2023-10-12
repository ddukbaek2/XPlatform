#include "BatchSprite.h"

namespace XPlatform
{
	void BatchSprite::OnCreate()
	{
		m_Texture = nullptr; // Ref<Texture>(nullptr);
	}

	void BatchSprite::OnDestroy()
	{
		m_Texture = nullptr; // Ref<Texture>(nullptr);
	}

	void BatchSprite::SetMaterial(Ref<Material> material)
	{
	}

	void BatchSprite::Render(Ref<IGL> gl)
	{
	}
}
