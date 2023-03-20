#pragma once
#include <string>

namespace hh
{
namespace base
{
class CSharedString
{
    char* m_data;

public:
    LWAPI(0x0369dddc, TODO)
    CSharedString();

    LWAPI(0x0369de40, TODO)
    void clearstr();
    
    LWAPI(0x0369dea4, TODO)
    void assign(const CSharedString& str);

    LWAPI(0x0369df10, TODO)
    CSharedString(const CSharedString& other);

    LWAPI(0x0369df74, 0x00c1f470)
    const char* c_str() const;

    LWAPI(0x0369e084, TODO)
    void newallocstr(const char* initialText, int len = -1);

    LWAPI(0x0369e154, TODO)
    CSharedString(const CSharedString& other, int off);

    LWAPI(0x0369e210, TODO)
    CSharedString(const CSharedString& other, int off, int count);

    LWAPI(0x0369e2d8, TODO)
    CSharedString(const std::string& str);

    LWAPI(0x0369e348, TODO)
    CSharedString(const char* first, const char* last);

    LWAPI(0x0369e3e0, TODO)
    CSharedString(const char* str);

    LWAPI(0x0369e460, TODO)
    CSharedString(const char* str, int off);

    LWAPI(0x0369e4f8, TODO)
    CSharedString(const char* str, int off, int count);

    LWAPI(0x0369e5b8, TODO)
    CSharedString(const char* str, int count, char val);

    LWAPI(0x0369e650, TODO)
    void reserve(int amount);

    LWAPI(0x0369e654, TODO)
    void clear();

    LWAPI(0x0369e658, TODO)
    std::size_t size() const;

    LWAPI(0x0369e6b4, TODO)
    std::size_t length() const;

    LWAPI(0x0369e6b8, TODO)
    std::size_t find(const char* str) const;

    LWAPI(0x0369e714, TODO)
    std::size_t find(const CSharedString& other) const;

    LWAPI(0x0369e778, TODO)
    std::size_t find(char val) const;

    LWAPI(0x0369e7d4, TODO)
    CSharedString& operator=(const char* str);

    LWAPI(0x0369e808, TODO)
    CSharedString& replace(int off, int count, const char* str, int count2);

    LWAPI(0x0369e888, TODO)
    CSharedString& replace(int off, int count, const char* str);

    LWAPI(0x0369e918, TODO)
    CSharedString& replace(int off, int count, const CSharedString& str);

    LWAPI(0x0369e9b0, TODO)
    void erase();

    // TODO: Implement the rest of these unused functions?

    LWAPI(0x0369ef90, TODO)
    ~CSharedString();

    LWAPI(0x0369efe0, TODO)
    CSharedString substr(int param_1, int param_2) const;

    // TODO: Implement the rest of these unused functions?

    LWAPI(0x0369f1b4, TODO)
    bool empty() const;

    LWAPI(0x0369f8e8, TODO)
    CSharedString& operator=(const CSharedString& other);

    // TODO
};
}
}
