#pragma once

#include <string>
#include <vector>
#include "Object.h"


namespace XPlatform
{
	class Text : public Object
	{
	private:
		std::wstring m_Value;

	public:
		Text();
		Text(const wchar_t* value);
		virtual ~Text();

		std::vector<Text*> 
		const wchar_t* ToCharArray(); // null-terminated style. new memory.
		const wchar_t* GetCharArray(); // null-terminated style.

		static std::vector<wchar_t*> Split(wchar_t* text, const wchar_t* delimiter);
	};
}