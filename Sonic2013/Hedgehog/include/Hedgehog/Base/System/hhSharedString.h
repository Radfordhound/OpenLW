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
    // Wii U: 0x0369dddc, PC: TODO
    CSharedString();

    // Wii U: 0x0369de40, PC: TODO
    void clearstr();
    
    // Wii U: 0x0369dea4, PC: TODO
    void assign(const CSharedString& str);

    // Wii U: 0x0369df10, PC: TODO
    CSharedString(const CSharedString& other);

    // Wii U: 0x0369df74, PC: 0x00c1f470
    const char* c_str() const;

    // Wii U: 0x0369e084, PC: TODO
    void newallocstr(const char* initialText, int len = -1);

    // Wii U: 0x0369e154, PC: TODO
    CSharedString(const CSharedString& other, int off);

    // Wii U: 0x0369e210, PC: TODO
    CSharedString(const CSharedString& other, int off, int count);

    // Wii U: 0x0369e2d8, PC: TODO
    CSharedString(const std::string& str);

    // Wii U: 0x0369e348, PC: TODO
    CSharedString(const char* first, const char* last);

    // Wii U: 0x0369e3e0, PC: TODO
    CSharedString(const char* str);

    // Wii U: 0x0369e460, PC: TODO
    CSharedString(const char* str, int off);

    // Wii U: 0x0369e4f8, PC: TODO
    CSharedString(const char* str, int off, int count);

    // Wii U: 0x0369e5b8, PC: TODO
    CSharedString(const char* str, int count, char val);

    // Wii U: 0x0369e650, PC: TODO
    void reserve(int amount);

    // Wii U: 0x0369e654 (THUNK), PC: TODO
    void clear();

    // Wii U: 0x0369e658, PC: TODO
    std::size_t size() const;

    // Wii U: 0x0369e6b4 (THUNK), PC: TODO
    std::size_t length() const;

    // Wii U: 0x0369e6b8, PC: TODO
    std::size_t find(const char* str) const;

    // Wii U: 0x0369e714, PC: TODO
    std::size_t find(const CSharedString& other) const;

    // Wii U: 0x0369e778, PC: TODO
    std::size_t find(char val) const;

    // Wii U: 0x0369e7d4, PC: TODO
    CSharedString& operator=(const char* str);

    // Wii U: 0x0369e808, PC: TODO
    CSharedString& replace(int off, int count, const char* str, int count2);

    // Wii U: 0x0369e888, PC: TODO
    CSharedString& replace(int off, int count, const char* str);

    // Wii U: 0x0369e918, PC: TODO
    CSharedString& replace(int off, int count, const CSharedString& str);

    // Wii U: 0x0369e9b0 (THUNK), PC: TODO
    void erase();

    // TODO: Implement the rest of these unused functions?

    // Wii U: 0x0369ef90, PC: TODO
    ~CSharedString();

    // Wii U: 0x0369efe0, PC: TODO
    CSharedString substr(int param_1, int param_2) const;

    // TODO: Implement the rest of these unused functions?

    // Wii U: 0x0369f1b4, PC: TODO
    bool empty() const;

    // Wii U: 0x0369f8e8, PC: TODO
    CSharedString& operator=(const CSharedString& other);

    // TODO
};
}
}
