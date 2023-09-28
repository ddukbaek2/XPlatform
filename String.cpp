#include "String.h"


namespace XPlatform
{
	int32_t SizeOfChar(unsigned char ch) {
		if ((ch & 0x80) == 0) return 1;
		if ((ch & 0xE0) == 0xC0) return 2;
		if ((ch & 0xF0) == 0xE0) return 3;
		if ((ch & 0xF8) == 0xF0) return 4;
		return 0;  // Invalid initial byte
	}


	String::String()
	{
		m_Data.clear();
	}

	String::String(const char* utf8String)
	{
		Set(utf8String);
	}

	String::String(const String& utf8String)
	{
		Set(utf8String.m_Data);
	}

	String::String(const std::string& utf8String)
	{
		Set(utf8String);
	}

	String::~String()
	{
	}

	std::string String::operator[](size_t index)
	{
		size_t i = 0;
		size_t charIndex = 0;
		while (i < m_Data.size() && charIndex <= index) {
			int size = SizeOfChar(static_cast<unsigned char>(m_Data[i]));
			if (size == 0) return "";  // Invalid UTF-8
			if (charIndex == index) {
				return m_Data.substr(i, size);
			}
			i += size;
			++charIndex;
		}
		return "";  // Out of range
	}

	void String::Set(const char* utf8String)
	{
		m_Data.assign(utf8String);
	}

	void String::Set(const String& utf8String)
	{
		m_Data.assign(utf8String.m_Data);
	}

	void String::Set(const std::string& utf8String)
	{
		m_Data.assign(utf8String);
	}

	void String::Append(const char* utf8String)
	{
		m_Data.append(utf8String);
	}

	void String::Append(const String& utf8String)
	{
		m_Data.append(utf8String.m_Data);
	}

	void String::Append(const std::string& utf8String)
	{
		m_Data.append(utf8String);
	}

	uint32_t String::GetCount()
	{
		size_t count = 0;
		for (size_t i = 0; i < m_Data.length(); ++i) {
			unsigned char ch = static_cast<unsigned char>(m_Data[i]);
			if (ch < 0x80 || (ch >= 0xC0 && ch < 0xF8)) {
				count++;
			}
		}
		return count;
	}

	const char* String::GetString()
	{
		return m_Data.c_str();
	}

	String String::Format(const char* utf8String, ...)
	{
		va_list args;
		va_start(args, utf8String);

		std::ostringstream oss;
		while (*utf8String != '\0') {
			if (*utf8String == '%') {
				++utf8String;
				if (*utf8String == 's') {
					const char* str = va_arg(args, const char*);
					oss << str;
				}
				else if (*utf8String == 'd') {
					int num = va_arg(args, int);
					oss << num;
				}
				else if (*utf8String == 'f') {
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

		return String(oss.str());
	}
}