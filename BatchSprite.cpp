#include "BatchSprite.h"

namespace XPlatform
{
	BatchSprite::BatchSprite()
	{
		m_Texture = Ref<Texture>(nullptr);
	}

	BatchSprite::~BatchSprite()
	{
		m_Texture.reset();
	}

	void BatchSprite::SetTexture(Ref<Texture> texture)
	{
		// 로드된 텍스쳐임을 전제로함.
		m_Texture = texture;
	}

	void BatchSprite::Render(Ref<IGL> gl)
	{
	}
}
