#pragma once

#include "XPlatform.h"
#include "IGL.h"
#include "Texture.h"


namespace XPlatform
{
	class BatchSprite
	{
	protected:
		Ref<Texture> m_Texture;

	public:
		BatchSprite();
		~BatchSprite();
		void SetTexture(Ref<Texture> texture);
		void Render(Ref<IGL> gl);
	};
}