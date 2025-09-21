#include <iostream>
using  namespace std;

class MyString {
private:
    char *str;
    int length;
public:
    MyString();
    MyString(int size);
    MyString(const char* s);
    MyString(const MyString& obj);
    MyString(MyString&& other) noexcept;
    ~MyString();

    MyString& operator=(const MyString& other);
    MyString& operator=(MyString&& other) noexcept;

    void Print();
    void Init();
    bool MyStrStr(const char* s);

    void MyStrcpy(const MyString& obj);
    int MyChr(char c) const;
    int MyStrLen() const;
    void MyStrCat(const MyString& b);
    void MyDelChr(char c);
    int MyStrCmp(const MyString& b) const;

};
