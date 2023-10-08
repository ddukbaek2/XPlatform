#pragma once

#include "XPlatform.h"
#include "Texture.h"


namespace XPlatform
{
	class TextureManager
	{
	private:
		std::map<String, Ref<Texture>> m_Textures;

	public:
		TextureManager();
		virtual ~TextureManager();

		void Add(const String& key, Ref<Texture> texture);
		void Remove(const String& key);

		Ref<Texture> Get(const String& key);
		bool Contains(const String& key);
	};
}
