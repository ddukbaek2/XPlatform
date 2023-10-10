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

	void BatchSprite::SetTexture(Ref<Texture> texture)
	{
		// 로드된 텍스쳐임을 전제로함.
		m_Texture = texture;
	}

	void BatchSprite::SetMaterial(Ref<Material> material)
	{
	}

	void BatchSprite::Render(Ref<IGL> gl)
	{
	}
}
