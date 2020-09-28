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
void String::copy(const String &Str) const
{
    strcpy(str, Str.str);
}
void String::ncopy(const String &Str,int n) const
{
    strncpy(str,Str.str,n);
    str[n]='\0';
}
void String::catenate(const String &Str) const
{
    strcat(str, Str.str);
}
void String::ncatenate(const String &Str,int n) const
{
    strncat(str, Str.str, n);
}
String & String::operator=(const String &Str)
{
    if(this==&Str)
        return *this;
    delete[] str;
    str = new char[strlen(Str.str) + 1];
    strcpy(str, Str.str);
    return *this;
}
bool operator==(const String &Str1, const String &Str2)
{
    if(strcmp(Str1.str,Str2.str)==0)
        return true;
    else
        return false;
}
bool operator!=(const String &Str1, const String &Str2)
{
    if(strcmp(Str1.str,Str2.str)!=0)
        return true;
    else
        return false;
}
bool operator>(const String &Str1, const String &Str2)
{
    if(strcmp(Str1.str,Str2.str))
        return true;
    else
        return false;
}
bool operator>=(const String &Str1, const String &Str2)
{
    if(strcmp(Str1.str,Str2.str)>=0)
        return true;
    else
        return false;
}
bool operator>(const String &Str1, const String &Str2)
{
    if(strcmp(Str1.str,Str2.str)<0)
        return true;
    else
        return false;
}
bool operator>=(const String &Str1, const String &Str2)
{
    if(strcmp(Str1.str,Str2.str)<=0)
        return true;
    else
        return false;
}

