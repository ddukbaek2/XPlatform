﻿#pragma once

#include "XPlatform.h"
#include "Object.h"
#include "String.h"


namespace XPlatform
{
	class Texture : public Object
	{
	private:
		std::vector<uint8_t> m_Pixels;
		uint32_t m_Width;
		uint32_t m_Height;

	public:
		Texture();
		virtual ~Texture();

		void Load(String& filename);
		void Unload();

		bool IsLoaded();
	};
}
