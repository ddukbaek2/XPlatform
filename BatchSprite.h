#pragma once

#include "XPlatform.h"
#include "IGL.h"
#include "Texture.h"


namespace XPlatform
{
	class BatchSprite
	{
	protected:
		std::shared_ptr<Texture> m_Texture;

	public:
		BatchSprite();
		~BatchSprite();
		void SetTexture(std::shared_ptr<Texture> texture);
		void Render(std::shared_ptr<IGL> gl);
	};
}