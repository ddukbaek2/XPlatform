#pragma once

#include "XPlatform.h"


namespace XPlatform
{
	class StringUtility
	{
	public:
		static inline uint8_t SizeOf(char ch)
		{
			if ((ch & 0x80) == 0) return 1;
			if ((ch & 0xE0) == 0xC0) return 2;
			if ((ch & 0xF0) == 0xE0) return 3;
			if ((ch & 0xF8) == 0xF0) return 4;
			return 0;  // Invalid initial byte
		}
	};
}