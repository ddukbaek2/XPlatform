#pragma once

#include <memory> // std::shared_ptr, std::weak_ptr, std::static_pointer_cast.
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
#include <future>
#include <iomanip> // std::setw, std::setfill
#include <cmath>

#define SafeDelete(name) if (name != nullptr) { delete name; name = nullptr; }
#define SafeDeleteArray(name) if (name != nullptr) { delete[] name; name = nullptr; }
#define UTF8(text) u8##text
#define CreateRef std::make_shared
#define CastRef std::static_pointer_cast


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전방 선언.
	/////////////////////////////////////////////////////////////////////////////
	class Object;
	class Application;
	class IGL;
	class SceneManager;


	/////////////////////////////////////////////////////////////////////////////
	// @ 타입 재정의.
	/////////////////////////////////////////////////////////////////////////////
	template<typename T> using Ref = std::shared_ptr<T>;
	template<typename T> using List = std::vector<T>;
	template<typename T> using Queue = std::queue<T>;
	template<typename T> using Stack = std::stack<T>;
	template<typename K, typename V> using Dictionary = std::map<K, V>;
	using String = std::string;

	template<typename... A> using Action = std::function<void(A...)>;
	template<typename... A> using Predicate = std::function<bool(A...)>;
	template<typename R, typename... A> using Func = std::function<R(A...)>;

	//using SimpleAction = std::function<void(void)>;
	//using FAction = Action<float>();
	//using FloatCallback = std::function<void(float)>;
	//using IGLCallback = std::function<void(Ref<IGL>)>;
	//using StringCallback = std::function<void(const String&)>;
}
