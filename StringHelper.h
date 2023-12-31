﻿#pragma once

#include "XPlatform.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 문자열 도우미.
	/////////////////////////////////////////////////////////////////////////////
	class StringHelper
	{
	public:
		static uint8_t GetCharSize(char ch);
		static String Format(const char* utf8String, ...);
		static String PercentEncode(const String& utf8String);
		static size_t GetCount(const String& utf8String);
	};
}
