#include "BatchSprite.h"

namespace XPlatform
{
	BatchSprite::BatchSprite()
	{
		m_Texture = std::shared_ptr<Texture>(nullptr);
	}

	BatchSprite::~BatchSprite()
	{
		m_Texture.reset();
	}

	void BatchSprite::SetTexture(std::shared_ptr<Texture> texture)
	{
		// 로드된 텍스쳐임을 전제로함.
		m_Texture = texture;
	}

	void BatchSprite::Render(std::shared_ptr<IGL> gl)
	{
	}
}
