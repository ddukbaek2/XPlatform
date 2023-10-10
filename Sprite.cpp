#include "Sprite.h"


namespace XPlatform
{
	void Sprite::OnCreate()
	{
		Base::OnCreate();

		m_Texture = nullptr; // Ref<Texture>(nullptr);
	}

	void Sprite::OnDestroy()
	{
		m_Texture = nullptr;

		Base::OnDestroy();
	}

	void Sprite::SetTexture(Ref<Texture> texture)
	{
		m_Texture = texture;
	}

	void Sprite::SetMaterial(Ref<Material> material)
	{

	}

	void Sprite::Render(Ref<IGL> gl)
	{
		//m_Texture->GetObjectID();
	}
}
