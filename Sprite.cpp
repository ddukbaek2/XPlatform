#include "Sprite.h"


namespace XPlatform
{
	Sprite::Sprite()
	{
		m_Texture = std::shared_ptr<Texture>(nullptr);
	}

	Sprite::~Sprite()
	{
		m_Texture.reset();
	}

	void Sprite::SetTexture(std::shared_ptr<Texture> texture)
	{
		m_Texture = texture;
	}

	void Sprite::Render(std::shared_ptr<IGL> gl)
	{
		//m_Texture->GetObjectID();
	}
}
