#include "Material.h"

namespace XPlatform
{
	void Material::OnCreate()
	{
		Base::OnCreate();

		m_Texture = nullptr; // Ref<Texture>(nullptr);
		m_Shader = nullptr;
	}
	
	void Material::OnDestroy()
	{
		m_Texture = nullptr; // Ref<Texture>(nullptr);
		m_Shader = nullptr;

		Base::OnDestroy();
	}

	void Material::SetTexture(Ref<Texture> texture)
	{
		m_Texture = texture;
	}

	void Material::SetShader(Ref<Shader> shader)
	{
		m_Shader = shader;
	}
}
