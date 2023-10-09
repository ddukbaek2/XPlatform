#pragma once

#include "XPlatform.h"
#include "Object.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 텍스쳐.
	/////////////////////////////////////////////////////////////////////////////
	class Texture : public Object
	{
	private:
		typedef Object Base;

	private:
		std::vector<uint8_t> m_Pixels;
		uint32_t m_Width;
		uint32_t m_Height;

	public:
		Texture();
		virtual ~Texture();

		void Load(const String& filename);
		void Unload();

		bool IsLoaded();
	};
}
