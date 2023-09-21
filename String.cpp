#include "String.h"
#include <cwchar> // wcstok


namespace XPlatform
{
    String::String()
    {
        m_Value.clear();
    }

    String::String(const wchar_t* value)
    {
        //m_Text.clear();
        //m_Text.append(text);
        m_Value.assign(value);
    }

    String::~String()
    {
        m_Value.clear();
    }

    //wchar_t* String::ToCharArray()
    //{
    //    auto originalString = m_Value.c_str();
    //    auto length = std::wcslen(originalString);
    //    auto copiedString = new wchar_t[length + 1];
    //    std::wcscpy(copiedString, originalString);
    //    return copiedString;
    //}

    const wchar_t* String::GetCharArray()
    {
        auto originalString = m_Value.c_str();
        return originalString;
    }

    //std::vector<wchar_t*> String::Split(wchar_t* text, const wchar_t* delimiter)
    //{
    //    std::vector<wchar_t*> tokens;
    //    wchar_t* token = wcstok(text, delimiter);
    //    while (token != nullptr)
    //    {
    //        tokens.push_back(token);
    //        token = wcstok(nullptr, delimiter);
    //    }

    //    return tokens;
    //}
}