#pragma once

#include "XPlatform.h"
#include "Object.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 텍스처.
	/////////////////////////////////////////////////////////////////////////////
	class Texture : public Object
	{
	private:
		typedef Object Base;

	private:
		std::vector<uint8_t> m_Pixels;
		uint32_t m_Width;
		uint32_t m_Height;
		bool m_IsAlphaTransparent;

	protected:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;

	public:
		void Load(const String& filename);
		void Unload();

		bool IsLoaded();
	};
}
