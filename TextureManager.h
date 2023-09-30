#pragma once
#include "Texture.h"
#include "XPlatform.h"
#include "Object.h"
#include "String.h"


namespace XPlatform
{
	class TextureManager
	{
	private:
		std::map<XString, Texture> m_Textures;

	public:
		TextureManager();
		virtual ~TextureManager();

		void Add(const XString& key, const Texture& texture);
		void Remove(const XString& key);

		Texture Get();
	};
}
