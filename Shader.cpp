#include "Shader.h"


namespace XPlatform
{
	void Shader::OnCreate()
	{
	}

	void Shader::OnDestroy()
	{
	}

	void Shader::SetName(const String& name)
	{
		m_Name.assign(name);
	}

	void Shader::SetShaderCode(const String& shaderCode)
	{
		m_ShaderCode.assign(shaderCode);
	}

	void Shader::SetProperty(const String& name, const String& value)
	{
	}

	void Shader::SetProperty(const String& name, int32_t value)
	{
	}

	void Shader::SetProperty(const String& name, float value)
	{
	}
}