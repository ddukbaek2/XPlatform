#include "String.h"


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
			auto size = strlen(utf8Chars); // string.h
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

	String::String(const std::vector<XChar>& utf8String)
	{
		for (auto i = 0; i < utf8String.size(); ++i)
		{
			auto utf8Char = utf8String[i];
			Append(utf8Char);
		}
	}

	String::String(const std::string& utf8String)
	{
		Set(utf8String);
	}

	String::~String()
	{
	}

	XChar String::operator[](int32_t index)
	{
		return GetAt(index);
	}

	bool String::operator () (const String& left, const String& right) const
	{
		return left.Compare(right);
	}

	bool String::operator<(const String& other) const
	{
		return m_Data < other.m_Data;
	}

	void String::Clear()
	{
		m_Data.clear();
	}

	void String::Set(const char* utf8String)
	{
		m_Data.assign(utf8String);
	}

	void String::Set(XChar& utf8Char)
	{
		auto charArray = utf8Char.GetCharArray();
		if (charArray == nullptr)
			return;

		m_Data.assign(charArray);
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

	void String::Append(XChar& utf8Char)
	{
		auto charArray = utf8Char.GetCharArray();
		if (charArray == nullptr)
			return;

		m_Data.append(charArray);
	}

	void String::Append(const String& utf8String)
	{
		m_Data.append(utf8String.m_Data);
	}

	void String::Append(const std::string& utf8String)
	{
		m_Data.append(utf8String);
	}

	std::vector<String> String::Split()
	{
		return std::vector<String>();
	}

	bool String::Compare(const String& utf8String) const
	{
		return m_Data.compare(utf8String.m_Data) == 0;
	}

	uint32_t String::GetCount() const
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

	XChar String::GetAt(int32_t index)
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

	const char* String::GetConstCharArray()
	{
		return m_Data.c_str();
	}

	const std::string& String::GetConstString() const
	{
		return m_Data;
	}

	//const std::string& String::GetConstString()
	//{
	//	return m_Data;
	//}

	std::vector<XChar> String::ToXCharArray()
	{
		std::vector<XChar> xcharArray;
		for (auto i = 0; i < GetCount(); ++i)
		{
			auto xchar = GetAt(i);
			xcharArray.push_back(xchar);
		}

		return std::vector<XChar>();
	}

	bool String::Equals(const String& utf8String)
	{
		return m_Data == utf8String.m_Data;
	}

	bool String::IsNullOrEmpty(const String& utf8String)
	{
		if (utf8String.m_Data.empty())
			return true;
		if (utf8String.GetCount() == 0)
			return true;

		return false;
	}

	String String::Empty()
	{
		return String(UTF8(""));
	}

	String String::Format(const char* utf8String, ...)
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

		return String(oss.str());
	}

	String String::PercentEncode(const String& utf8String)
	{
		std::ostringstream oss;
		for (uint8_t ch : utf8String.GetConstString())
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

		return String(oss.str());
	}
}
