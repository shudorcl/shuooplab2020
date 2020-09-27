#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;
String::String(const char *s)
{
    str = new char[strlen(s) + 1];
    strcpy(str, s);
}
int String::find(const String &Str) const
{
    int i;
}
void String::copy(const String &Str) const
{
    strcpy(str, Str.str);
}
