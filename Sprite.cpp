#include "Sprite.h"


namespace XPlatform
{
	Sprite::Sprite()
	{
		m_Texture = Ref<Texture>(nullptr);
	}

	Sprite::~Sprite()
	{
		m_Texture.reset();
	}

	void Sprite::SetTexture(Ref<Texture> texture)
	{
		m_Texture = texture;
	}

	void Sprite::Render(Ref<IGL> gl)
	{
		//m_Texture->GetObjectID();
	}
}
