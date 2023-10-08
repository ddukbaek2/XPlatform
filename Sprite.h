#pragma once

#include "XPlatform.h"
#include "Object.h"
#include "IGL.h"
#include "Texture.h"


namespace XPlatform
{
	class Sprite : public Object
	{
	protected:
		Ref<Texture> m_Texture;

	public:
		Sprite();
		virtual ~Sprite();
		void SetTexture(Ref<Texture> texture);
		void Render(Ref<IGL> gl);
	};
}
