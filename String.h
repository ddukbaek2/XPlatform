#pragma once

#include <string>
#include <vector>
#include "Object.h"


namespace XPlatform
{
	class String : public Object
	{
	private:
		std::wstring m_Value;

	public:
		String();
		String(const wchar_t* value);
		virtual ~String();

		//wchar_t* ToCharArray(); // null-terminated style. new memory.
		const wchar_t* GetCharArray(); // null-terminated style.

		//static std::vector<wchar_t*> Split(wchar_t* text, const wchar_t* delimiter);
	};
}