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
		std::shared_ptr<Texture> m_Texture;

	public:
		Sprite();
		virtual ~Sprite();
		void SetTexture(std::shared_ptr<Texture> texture);
		void Render(std::shared_ptr<IGL> gl);
	};
}
