#pragma once

#include <memory> // Reference, std::weak_ptr.
#include <string> // std::string.
#include <map> // std::map.
#include <vector> // std::vector.
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <functional>
#include <chrono>
#include <random>
#include <cstdint> // int8_t, int16_t, int32_t, int64_t, uint8_t, uint16_t, uint32_t, uint64_t.
#include <sstream>
#include <cstdarg> // va_start, va_end, va_arg.
#include <thread>
#include <iomanip> // std::setw, std::setfill

#define SAFE_DELETE(name) if (name != nullptr) { delete name; name = nullptr; }
#define SAFE_DELETE_ARRAY(name) if (name != nullptr) { delete[] name; name = nullptr; }
//#define TEXT(text) L##text
#define UTF8(TEXT) u8##TEXT
#define _RAWTEXT(TEXT) R##TEXT // "R("void Function(){ }")";
#define interface struct
//#define REF(TYPE) Reference<TYPE>


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전방선언.
	/////////////////////////////////////////////////////////////////////////////
	class Object;
	class String;
	class Application;
	//class ApplicationEventHandler;
	class IGL;
	class SceneManager;


	/////////////////////////////////////////////////////////////////////////////
	// @ 타입재정의.
	/////////////////////////////////////////////////////////////////////////////
	//typedef std::function<void(void)> VoidCallback;
	//typedef std::function<void(float)> FloatCallback;
	//typedef std::function<void(Reference<IGL>)> IGLCallback;
	//typedef std::function<void(const String&)> StringCallback;
	template<typename T> using Ref = std::shared_ptr<T>;
	using VoidCallback = std::function<void(void)>;
	using FloatCallback = std::function<void(float)>;
	using IGLCallback = std::function<void(Ref<IGL>)>;
	using StringCallback = std::function<void(const String&)>;
}
