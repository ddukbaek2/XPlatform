#pragma once

#include "XPlatform.h"


namespace XPlatform
{
	// UTF8
	class String
	{
	private:
		std::string m_Data;

	public:
		String();
		String(const char* utf8String);
		String(const String& utf8String);
		String(const std::string& utf8String);
		virtual ~String();

		String operator[](size_t index);

		void Set(const char* utf8String);
		void Set(const String& utf8String);
		void Set(const std::string& utf8String);

		void Append(const char* utf8String);
		void Append(const String& utf8String);
		void Append(const std::string& utf8String);

		uint32_t GetCount();
		const char* GetString();

	public:
		static String Format(const char* utf8String, ...);
	};
}