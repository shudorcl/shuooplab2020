#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;
//rcl's construc func
String::String(const char *s)
{
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    str[strlen(s)] = '\0';
    cout << "A String is constructed.("
         << str << ')' << endl;
}
String::String(const char *s, int n)
{
    if (strlen(s) < n)
        str = new char[strlen(s) + 1];
    else
        str = new char[n + 1];
    strcpy(str, s);
    str[n] = '\0';
    cout << "A String is constructed.("
         << str << ')' << endl;
}
String::String(int n, char c)
{
    int i;
    str = new char[n + 1];
    for (i = 0; i < n; i++)
        str[i] = c;
    str[n] = '\0';
    cout << "A String is constructed.("
         << str << ')' << endl;
}
String::String(const String &Str)
{
    str = new char[strlen(Str.str) + 1];
    strcpy(str, Str.str);
    cout << "A String is constructed.("
         << str << ')' << endl;
}
String::~String()
{
    static int DestructCount = 0;
    cout << "Now we'll destruct a String.("
         << str << ')';
    if (str != NULL)
        delete[] str;
    DestructCount++;

    cout << '(' << DestructCount << ')' << endl;
}
int String::length() const
{
    return strlen(str);
}
//rcl's official work
int String::find(const String &Str) const
{
    int i, j, m, n, flag;
    m = strlen(Str.str);
    n = strlen(str);
    if (m > n)
        return -1;
    for (i = 0; i < n - m; i++)
    {
        flag = 1;
        for (j = 0; j < m; j++)
        {
            if (Str.str[j] != str[i + j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            return i;
    }
    return -1;
}
int String::rfind(const String &Str) const
{
    int i, j, m, n, flag;
    m = strlen(Str.str);
    n = strlen(str);
    if (m > n)
        return -1;
    for (i = n - m - 1; i >= 0; i--)
    {
        flag = 1;
        for (j = m - 1; j >= 0; j--)
        {
            if (Str.str[j] != str[i + j])
            {
                flag = 0;
                break;
            }
        }
        if (flag)
            return i;
    }
    return -1;
}
/*char* &String::reverse()
{
//Well,as for Chinese ,it may not work correctly...
    int i, j, length = strlen(str);
    char *temp = new char[length+1];
    for (i = 0,j=length; i < length;i++,j--)
    {
        temp[i] = str[j - 1];
    }
    temp[length] = '\0';
    strcpy(str, temp);
    delete[] temp;
    return str;
}*/
//Maybe we should use strrev...
char* &String::reverse()
{
    strrev(str);
    return str;
}
char* &String::ChineseReverse() 
{
	int length = strlen(str),t=length;
	for (int i=0; i<length/2; i+=2,t-=2) {
		int ret = str[i];
		str[i] = str[t-2];
		str[t-2] = ret;

		ret = str[i+1];
		str[i+1] = str[t-1];
		str[t-1] = ret;
	}
    return str;
}
char *&String::copy(const String &Str)
{
    strcpy(str, Str.str);
    return str;
}
char *&String::ncopy(const String &Str, int n)
{
    strncpy(str, Str.str, n);
    str[n] = '\0';
    return str;
}
char *&String::catenate(const String &Str)
{
    strcat(str, Str.str);
    return str;
}
char *&String::ncatenate(const String &Str, int n)
{
    strncat(str, Str.str, n);
    return str;
}
String &String::operator=(const String &Str)
{
    if (this == &Str)
        return *this;
    delete[] str;
    str = new char[strlen(Str.str) + 1];
    strcpy(str, Str.str);
    return *this;
}
bool operator==(const String &Str1, const String &Str2)
{
    if (strcmp(Str1.str, Str2.str) == 0)
        return true;
    else
        return false;
}
bool operator!=(const String &Str1, const String &Str2)
{
    if (strcmp(Str1.str, Str2.str) != 0)
        return true;
    else
        return false;
}
bool operator>(const String &Str1, const String &Str2)
{
    if (strcmp(Str1.str, Str2.str))
        return true;
    else
        return false;
}
bool operator>=(const String &Str1, const String &Str2)
{
    if (strcmp(Str1.str, Str2.str) >= 0)
        return true;
    else
        return false;
}
bool operator<(const String &Str1, const String &Str2)
{
    if (strcmp(Str1.str, Str2.str) < 0)
        return true;
    else
        return false;
}
bool operator<=(const String &Str1, const String &Str2)
{
    if (strcmp(Str1.str, Str2.str) <= 0)
        return true;
    else
        return false;
}
char &String::operator[](int index) const
{
    return str[index];
}
void String::Show() const
{
    cout << str << endl;
}

char& String::front() const
{
    return str[0];
}
char &String::back() const
{
    return str[strlen(str)-1];
}
