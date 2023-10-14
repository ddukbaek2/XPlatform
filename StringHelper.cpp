#include "StringHelper.h"


namespace XPlatform
{
	uint8_t StringHelper::GetCharSize(char ch)
	{
		if ((ch & 0x80) == 0) return 1;
		if ((ch & 0xE0) == 0xC0) return 2;
		if ((ch & 0xF0) == 0xE0) return 3;
		if ((ch & 0xF8) == 0xF0) return 4;
		return 0;  // Invalid initial byte
	}

	std::string StringHelper::Format(const char* utf8String, ...)
	{
		va_list args;
		va_start(args, utf8String);

		std::ostringstream oss;
		while (*utf8String != '\0')
		{
			if (*utf8String == '%')
			{
				++utf8String;
				if (*utf8String == 's')
				{
					const char* str = va_arg(args, const char*);
					oss << str;
				}
				else if (*utf8String == 'd')
				{
					int num = va_arg(args, int);
					oss << num;
				}
				else if (*utf8String == 'f')
				{
					double num = va_arg(args, double);
					oss << num;
				}
				else {
					// Unknown format specifier; you can extend this as needed.
					oss << '%';
					--utf8String;  // So that the next iteration will process this character again
				}
			}
			else {
				oss << *utf8String;
			}
			++utf8String;
		}

		va_end(args);

		return oss.str();
	}

	String StringHelper::PercentEncode(const String& utf8String)
	{
		std::ostringstream oss;
		for (uint8_t ch : utf8String)
		{
			// ASCII 문자는 유지.
			if (ch >= 0x20 && ch <= 0x7E)
			{
				oss << ch;
			}
			// ASCII 범위를 벗어나는 문자는 백분율 인코딩.
			else
			{
				oss << '%' << std::uppercase << std::hex << std::setw(2) << std::setfill('0') << (int)ch;
			}
		}

		return oss.str();
	}

	size_t StringHelper::GetCount(const String& utf8String)
	{
		size_t count = 0;
		for (uint8_t ch : utf8String)
		{
			if (ch < 0x80 || (ch >= 0xC0 && ch < 0xF8))
			{
				count++;
			}
		}
		return count;
	}
}
