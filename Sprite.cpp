#include "Sprite.h"


namespace XPlatform
{
	void Sprite::OnCreate()
	{
		Base::OnCreate();

		m_Texture = Ref<Texture>(nullptr);
	}

	void Sprite::OnDestroy()
	{
		m_Texture.reset();

		Base::OnDestroy();
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
