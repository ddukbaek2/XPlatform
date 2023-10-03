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
		std::map<String, Texture> m_Textures;

	public:
		TextureManager();
		virtual ~TextureManager();

		void Add(const String& key, const Texture& texture);
		void Remove(const String& key);

		//Texture Get();
	};
}
