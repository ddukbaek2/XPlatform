#include "XString.h"


namespace XPlatform
{
	XChar::XChar()
	{
		m_Chars = nullptr;
	}

	XChar::XChar(const char* utf8Chars)
	{
		if (utf8Chars == nullptr)
		{
			m_Chars = nullptr;
		}
		else
		{
			auto size = sizeof(utf8Chars) / sizeof(char);
			m_Chars = new char[size + 1];
			for (auto i = 0; i < size; ++i)
			{
				m_Chars[i] = utf8Chars[i];
			}
			m_Chars[size] = '\0';
		}
	}

	XChar::XChar(const std::string& utf8Chars)
	{
		if (utf8Chars.empty())
		{
			m_Chars = nullptr;
		}
		else
		{
			auto length = utf8Chars.length();
			m_Chars = new char[length + 1];
			for (auto i = 0; i < length; ++i)
			{
				m_Chars[i] = utf8Chars[i];
			}
			m_Chars[length] = '\0';
		}
	}

	XChar::~XChar()
	{
		SAFE_DELETE_ARRAY(m_Chars);
	}

	const char* XChar::GetCharArray()
	{
		return m_Chars;
	}

	uint8_t XChar::SizeOf()
	{
		if (m_Chars == nullptr)
			return 0;

		auto ch = m_Chars[0];
		return SizeOf(ch);
	}

	uint8_t XChar::SizeOf(char ch)
	{
		if ((ch & 0x80) == 0) return 1;
		if ((ch & 0xE0) == 0xC0) return 2;
		if ((ch & 0xF0) == 0xE0) return 3;
		if ((ch & 0xF8) == 0xF0) return 4;
		return 0;  // Invalid initial byte
	}

	XString::XString()
	{
		m_Data.clear();
	}

	XString::XString(const char* utf8String)
	{
		Set(utf8String);
	}

	XString::XString(const XString& utf8String)
	{
		Set(utf8String.m_Data);
	}

	XString::XString(const std::vector<XChar>& utf8String)
	{
		for (auto i = 0; i < utf8String.size(); ++i)
		{
			auto utf8Char = utf8String[i];
			Append(utf8Char);
		}
	}

	XString::XString(const std::string& utf8String)
	{
		Set(utf8String);
	}

	XString::~XString()
	{
	}

	XChar XString::operator[](int32_t index)
	{
		return GetAt(index);
	}

	void XString::Clear()
	{
		m_Data.clear();
	}

	void XString::Set(const char* utf8String)
	{
		m_Data.assign(utf8String);
	}

	void XString::Set(XChar& utf8Char)
	{
		auto charArray = utf8Char.GetCharArray();
		if (charArray == nullptr)
			return;

		m_Data.assign(charArray);
	}

	void XString::Set(const XString& utf8String)
	{
		m_Data.assign(utf8String.m_Data);
	}

	void XString::Set(const std::string& utf8String)
	{
		m_Data.assign(utf8String);
	}

	void XString::Append(const char* utf8String)
	{
		m_Data.append(utf8String);
	}

	void XString::Append(XChar& utf8Char)
	{
		auto charArray = utf8Char.GetCharArray();
		if (charArray == nullptr)
			return;

		m_Data.append(charArray);
	}

	void XString::Append(const XString& utf8String)
	{
		m_Data.append(utf8String.m_Data);
	}

	void XString::Append(const std::string& utf8String)
	{
		m_Data.append(utf8String);
	}

	std::vector<XString> XString::Split()
	{
		return std::vector<XString>();
	}

	uint32_t XString::GetCount()
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

	XChar XString::GetAt(int32_t index)
	{
		uint32_t i = 0;
		uint32_t charIndex = 0;
		while (i < m_Data.size() && charIndex <= index)
		{
			uint32_t size = XChar::SizeOf(static_cast<unsigned char>(m_Data[i]));
			if (size == 0)
				return XChar(nullptr);  // Invalid UTF-8
			if (charIndex == index)
				return XChar(m_Data.substr(i, size));

			i += size;
			++charIndex;
		}

		return XChar(nullptr);  // Out of range
	}

	const char* XString::GetConstCharArray()
	{
		return m_Data.c_str();
	}

	const std::string& XString::GetConstString()
	{
		return m_Data;
	}

	std::vector<XChar> XString::ToXCharArray()
	{
		std::vector<XChar> xcharArray;
		for (auto i = 0; i < GetCount(); ++i)
		{
			auto xchar = GetAt(i);
			xcharArray.push_back(xchar);
		}

		return std::vector<XChar>();
	}

	bool XString::Equals(const XString& utf8String)
	{
		return m_Data == utf8String.m_Data;
	}

	bool XString::IsNullOrEmpty(XString* utf8String)
	{
		if (utf8String == nullptr)
			return true;

		if (utf8String->GetCount() == 0)
			return true;

		return false;
	}

	XString XString::Empty()
	{
		return XString(UTF8(""));
	}

	XString XString::Format(const char* utf8String, ...)
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

		return XString(oss.str());
	}
}