#include "String.h"
#include <cwchar> // wcstok


namespace XPlatform
{
    Text::Text()
    {
        m_Value.clear();
    }

    Text::Text(const wchar_t* value)
    {
        //m_Text.clear();
        //m_Text.append(text);
        m_Value.assign(value);
    }

    Text::~Text()
    {
        m_Value.clear();
    }

    const wchar_t* Text::GetString()
    {
        auto originalString = m_Value.c_str();
        return originalString;
    }

    const wchar_t* Text::ToString()
    {
        auto originalString = m_Value.c_str();
        auto length = std::wcslen(originalString);
        auto copiedString = new wchar_t[length + 1];
        std::wcscpy(copiedString, originalString);
        return copiedString;
    }

    std::vector<wchar_t*> Text::Split(wchar_t* text, const wchar_t* delimiter)
    {
        std::vector<wchar_t*> tokens;
        wchar_t* token = wcstok(text, delimiter);
        while (token != nullptr)
        {
            tokens.push_back(token);
            token = wcstok(nullptr, delimiter);
        }

        return tokens;
    }
}