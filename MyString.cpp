#include <iostream>
#include "MyString.h"
using namespace std;

MyString::MyString() {
    length = 80;
    str = new char[length + 1];
    str[0] = '\0';
    MyString::count = 0;
}

MyString::MyString(int size) {
    length = size;
    str = new char[length + 1];
    str[0] = '\0';
}

MyString::MyString(const char* s) {
    if (s == nullptr) {
        length = 0;
        str = new char[1];
        str[0] = '\0';
    } else {
        length = strlen(s);
        str = new char[length + 1];
        strcpy(str, s);
    }
}

MyString::MyString(const MyString& obj) {
    length = obj.length;
    str = new char[length + 1];
    if (obj.str != nullptr) {
        strcpy(str, obj.str);
    } else {
        str[0] = '\0';
    }
    count = obj.count;
}

MyString::MyString(MyString&& other) noexcept {
    str = other.str;
    length = other.length;

    other.str = nullptr;
    other.length = 0;
}

MyString::~MyString() {
    delete[] str;
}

MyString& MyString::operator=(const MyString& other) {
    if (this != &other) {
        delete[] str;
        length = other.length;
        str = new char[length + 1];
        if (other.str != nullptr) {
            strcpy(str, other.str);
        } else {
            str[0] = '\0';
        }
    }
    return *this;
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] str;

        str = other.str;
        length = other.length;

        other.str = nullptr;
        other.length = 0;
    }
    return *this;
}

void MyString::Print() {
    if (str != nullptr) {
        cout << str << endl;
    } else {
        cout << "(empty)" << endl;
    }
}

void MyString::PrintStatic() {
    cout << "Count: " << MyString::count << endl;
}

void MyString::Init() {
    cout << "Введите строку: ";
    cin.getline(str, length + 1);
}

bool MyString::MyStrStr(const char* s) {
    if (str == nullptr || s == nullptr) {
        return false;
    }

    char* result = strstr(str, s);
    return (result != nullptr);
}

void MyString::MyStrcpy(const MyString& obj) {
    if (this != &obj) {
        delete[] str;
        length = obj.length;
        str = new char[length + 1];
        if (obj.str != nullptr) {
            strcpy(str, obj.str);
        } else {
            str[0] = '\0';
        }
    }
}

int MyString::MyChr(char c) const {
    if (str == nullptr) return -1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == c) {
            return i;
        }
    }
    return -1;
}

int MyString::MyStrLen() const {
    if (str == nullptr) return 0;
    return strlen(str);
}

void MyString::MyStrCat(const MyString& b) {
    if (b.str == nullptr) return;

    int currentLen = (str != nullptr) ? strlen(str) : 0;
    int newLen = currentLen + strlen(b.str);

    if (newLen <= length) {
        if (str != nullptr) {
            strcat(str, b.str);
        } else {
            strcpy(str, b.str);
        }
    } else {
        // Нужно расширить буфер
        char* newStr = new char[newLen + 1];
        if (str != nullptr) {
            strcpy(newStr, str);
            strcat(newStr, b.str);
        } else {
            strcpy(newStr, b.str);
        }
        delete[] str;
        str = newStr;
        length = newLen;
    }
}

void MyString::MyDelChr(char c) {
    if (str == nullptr) return;

    int writePos = 0;
    for (int readPos = 0; str[readPos] != '\0'; readPos++) {
        if (str[readPos] != c) {
            str[writePos++] = str[readPos];
        }
    }
    str[writePos] = '\0';
}

int MyString::MyStrCmp(const MyString& b) const {
    if (str == nullptr && b.str == nullptr) return 0;
    if (str == nullptr) return -1;
    if (b.str == nullptr) return 1;

    int result = strcmp(str, b.str);
    if (result < 0) return -1;
    if (result > 0) return 1;
    return 0;
}

MyString MyString::operator+(MyString& obj) { // MyString rez = obj + obj2;
    MyString result(this->length + obj.length);

    strcpy(result.str, this->str);
    strcat(result.str, obj.str);

    return result;
}

MyString MyString::operator+(const MyString& obj) { // MyString rez2 = obj + "!!!";
    MyString result(this->length + obj.length);

    strcpy(result.str, this->str);
    strcat(result.str, obj.str);

    return result;
}

MyString MyString::operator+(char c) { // MyString rez3 = obj + '?';
    MyString result(this->length + 1);

    strcpy(result.str, this->str);
    int len = strlen(result.str);
    result.str[len] = c;
    result.str[len + 1] = '\0';

    return result;
}

MyString MyString::operator-(const MyString& obj) { // MyString rez4 = obj - "world";
    MyString result(this->length);
    strcpy(result.str, this->str);

    char* pos = strstr(result.str, obj.str);
    while (pos != nullptr) {
        strcpy(pos, pos + strlen(obj.str));
        pos = strstr(result.str, obj.str);
    }

    return result;
}

MyString& MyString::operator=(MyString&& other) noexcept {
    if (this != &other) {
        delete[] str;

        str = other.str;
        length = other.length;

        other.str = nullptr;
        other.length = 0;
    }
    return *this;
}