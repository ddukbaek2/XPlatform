#pragma once

#include <memory> // std::shared_ptr, std::weak_ptr.
#include <string> // std::wstring.
#include <map> // std::map.
#include <vector> // std::vector.
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <functional>
#include <chrono>
#include <cstdint> // int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t.
#include <sstream>
#include <cstdarg> // va_start, va_end, va_arg.


#define SAFE_DELETE(name) if (name != nullptr) { delete name; name = nullptr; }
#define SAFE_DELETE_ARRAY(name) if (name != nullptr) { delete[] name; name = nullptr; }
//#define TEXT(text) L##text
#define UTF8(TEXT) u8##TEXT

namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전방선언.
	/////////////////////////////////////////////////////////////////////////////
	class XApplication;
	class XApplicationEventHandler;
	class XGL;


	/////////////////////////////////////////////////////////////////////////////
	// @ 타입재정의.
	/////////////////////////////////////////////////////////////////////////////
	typedef std::function<void(void)> VoidFunction;
	typedef std::function<void(float)> FloatFunction;
	typedef std::function<void(std::shared_ptr<XGL>)> XGLFunction;
}