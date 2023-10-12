#pragma once

#include "XPlatform.h"
#include "Object.h"
#include "Texture.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 셰이더.
	/////////////////////////////////////////////////////////////////////////////
	class Shader : public Object
	{
	private:
		typedef Object Base;

	protected:
		String m_Name;
		String m_ShaderCode;

	protected:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;

	public:
		void SetName(const String& name);
		void SetShaderCode(const String& shaderCode);

		void SetProperty(const String& name, const String& value);
		void SetProperty(const String& name, int32_t value);
		void SetProperty(const String& name, float value);
	};
}
