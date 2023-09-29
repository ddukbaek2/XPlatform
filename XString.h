#pragma once

#include "XPlatform.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 가변길이 문자 클래스 (UTF8).
	/////////////////////////////////////////////////////////////////////////////
	class XChar
	{
	private:
		char* m_Chars;

	public:
		XChar();
		XChar(const char* utf8Chars);
		XChar(const std::string& utf8Chars);
		virtual ~XChar();
		
		const char* GetCharArray();
		uint8_t SizeOf();

	public:
		static uint8_t SizeOf(char ch);
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 가변길이 문자열 클래스 (UTF8).
	/////////////////////////////////////////////////////////////////////////////
	class XString
	{
	private:
		std::string m_Data;

	public:
		XString();
		XString(const char* utf8String);
		XString(const XString& utf8String);
		XString(const std::vector<XChar>& utf8String);
		XString(const std::string& utf8String);
		virtual ~XString();

		XChar operator[](int32_t index);

		void Clear();

		void Set(const char* utf8String);
		void Set(XChar& utf8Char);
		void Set(const XString& utf8String);
		void Set(const std::string& utf8String);

		void Append(const char* utf8String);
		void Append(XChar& utf8Char);
		void Append(const XString& utf8String);
		void Append(const std::string& utf8String);
	
		std::vector<XString> Split();

		//XString Remove(int32_t index, uint32_t count);
		//XString SubString(int32_t index, uint32_t count);

		uint32_t GetCount();
		XChar GetAt(int32_t index);
		const char* GetConstCharArray();
		const std::string& GetConstString();
		std::vector<XChar> ToXCharArray();

		bool Equals(const XString& utf8String);

	public:
		static bool IsNullOrEmpty(XString* utf8String);
		static XString Empty();
		static XString Format(const char* utf8String, ...);
		//static XString Replace();
	};
}