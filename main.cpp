#include <iostream>
#include "MyString.h"
using  namespace std;

int main() {
    MyString obj("Hello World");
    obj.Print();

    MyString obj2("Hello World");
    obj2.Print();

    MyString rez = obj + obj2;
    rez.Print();
    MyString rez2 = obj + "!!!";
    rez2.Print();
    MyString rez3 = obj + "?";
    rez3.Print();
    MyString rez4 = obj + "world";
    rez4.Print();
}