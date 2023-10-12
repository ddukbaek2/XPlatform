#pragma once

#include "XPlatform.h"
#include "Object.h"
#include "Texture.h"
#include "Shader.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 메터리얼.
	/////////////////////////////////////////////////////////////////////////////
	class Material : public Object
	{
	private:
		typedef Object Base;

	protected:
		String m_Name;
		Ref<Texture> m_Texture;
		Ref<Shader> m_Shader;

	protected:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;

	public:
		void SetTexture(Ref<Texture> texture);
		void SetShader(Ref<Shader> shader);
	};
}
