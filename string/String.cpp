#include "String.h"
#include <string.h>
#include <iostream>
#include <string>
using namespace std;
//rcl's construc func
String::String(const char *s)
{
    //use the entered character as the value of Str of the data member of the target object
    str = new char[strlen(s) + 1];
    strcpy(str, s);
    str[strlen(s)] = '\0';
    cout << "A String is constructed.("
         << str << ')' << endl;
}
String::String(const char *s, unsigned long n)
{
    //take n characters of the input string as the value of Str of the data member of the target object
    if (strlen(s) < n)
        str = new char[strlen(s) + 1];
    else
        str = new char[n + 1];
    strcpy(str, s);
    str[n] = '\0';
    cout << "A String is constructed.(Method 2)("
         << str << ')' << endl;
}
String::String(int n, char c)
{
    //repeat the input character n times as the value of Str of the data member of the target object
    int i;
    str = new char[n + 1];
    for (i = 0; i < n; i++)
        str[i] = c;
    str[n] = '\0';
    cout << "A String is constructed.(Method 3)("
         << str << ')' << endl;
}

String::String(const String &Str, int pos, int n)
{
    //take n characters from a certain position (pos) from the value of str in the data member of the reference object as the value of Str of the data member of the target object
    int i, m;
    m = (int)strlen(Str.str);
    if (pos > m)
    {
        str = new char[1];
        str[0] = '\0';
        return;
    }
    if (m - pos < n)
        n = m - pos;
    if (n < 0)
        n = 0;
    str = new char[n + 1];
    for (i = 0; i < n; i++)
        str[i] = Str.str[pos + i];
    str[i] = '\0';
    cout << "A String is constructed.(Method 4)("
         << str << ')' << endl;
}

String::String(const String &Str)
{
    //use the value of str in the data member of the input object as the value of Str in the data member of the target object
    str = new char[strlen(Str.str) + 1];
    strcpy(str, Str.str);
    cout << "A String is constructed.(Method copy)("
         << str << ')' << endl;
}
String::~String()
{
    static int DestructCount = 0;
    cout << "Now we'll destruct a String.("
         << str << ')';
    if (str != NULL)
        delete[] str;
    str = NULL;
    DestructCount++;

    cout << '(' << DestructCount << ')' << endl;
}
unsigned long String::length() const
{
    //returns the length of Str in the data member of the target object
    return strlen(str);
}
//rcl's official work
long String::find(const String &Str) const
{
    //find whether there are characters in str in the data member of the target object that match the str in the data member of the input object
    unsigned long i, j, m, n, flag;
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
long String::rfind(const String &Str) const
{
    //Start from the right to find out whether there is a character matching str in the data member of the input object in the str in the data member of the target object
    unsigned long i, j, m, n, flag;
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

//the defination of append
String &String::append(const char *s)
{
    //Splice the incoming string directly behind the str of the object data member
    cout<<"Splice the incoming string directly behind the str of the object data member:"<<endl;
    char temp[100];
    strcpy(temp,str);
    strcat(temp,s);
    str=new char[m_str+strlen(s)];
    strcpy(str, temp);
    m_str += strlen(s);
    return *this;
}

String &String::append(const String &s, unsigned long pos, unsigned long n)
{
    //Cut a certain number (n) of characters from a certain position (pos) of the str value of the data member of the incoming object to splice behind the str of the target object data member
    cout<<"Cut a certain number (n) of characters from a certain position (POS) of the str value of the data member of the incoming object to splice behind the str of the target object data member:"<<endl;
    char temp[1024];
    int num;
    num=(int)strlen(str);
    strcpy(temp,str);
    for(unsigned long i=pos;i<pos+n;i++)
    {
        temp[num]=s.str[i];
        num++;
    }
    temp[num]='\0';
    str=new char[m_str+n];
    strcpy(str,temp);
    return *this;
}

//the functiong of the empty
bool String::empty() const
{
    // determine whether str in the data member of the target object is empty
    if (str[0] == '\0')
        return true;
    else
        return false;
}

String &String::append(const String &s)
{
    //Directly splice the str value of the data member of the incoming object to the back of the str of the target data member
    cout<<"Directly splice the str value of the data member of the incoming object to the back of the str of the target data member:"<<endl;
    char temp[1024];
    strcpy(temp, str);
    strcat(temp, s.str);
    str=new char[strlen(str)+strlen(s.str)];
    strcpy(str,temp);
    m_str += strlen(s.str);
    return *this;
}

String &String::append(int num, const char s)
{
    //Set a certain number (n) of repetitions for the incoming string and splice it behind the str of the target object data member
    cout<<"Set a certain number (n) of repetitions for the incoming string and splice it behind the str of the target object data member:"<<endl;
    char p_temp[100];
    strcpy(p_temp,str);
    int i =(int)strlen(str);
    for (; i<num; i++)
    {
        p_temp[i] = s;
    }
    p_temp[i] = '\0';
    str=new char[strlen(str)+num];
    strcpy(str,p_temp);
    m_str += num;
    return *this;
}

//the function of insert
String &String::insert(int pos, const char *s)
{
    //insert the input character from a certain position (pos) of str in the data member of the target object
    int n = (int)strlen(str);
    if (pos > n)
        pos = n;
    char *p = new char[strlen(str) + strlen(s) + 1];
    strncpy(p, str, pos);
    p[pos] = '\0';
    strcat(p, s);
    strcat(p, str + pos);
    delete[] str;
    str = p;
    return *this;
}

//the function of substr
String String::substr(int pos, int n)
{
    //Extract n characters from a position (pos) of str in the data member of the target object
    String temp(*this, pos, n);
    return temp;
}
//the function of swap
String &String::swap(char *s)
{
    //Swap the str in the data member of the target object with the input string
    cout<<"Swap the str in the data member of the target object with the input string: "<<endl;
    char p_temp[100];
    int size = (int)strlen(s);
    strcpy(p_temp, s);
    p_temp[size] = '\0';
    str=new char[size];
    strcpy(str, p_temp);
    return *this;
}
String &String::swap(const String &s)
{
    //Swap the str in the data member of the target object with the str in the data member of the input object
    cout<<"Swap the str in the data member of the target object with the str in the data member of the input object: "<<endl;
    char p_temp[100];
    int size = (int)strlen(s.str);
    strcpy(p_temp, s.str);
    p_temp[size] = '\0';
    strcpy(str, p_temp);
    return *this;
}

//the function of clear
void String::clear()
{
    //Clear the value of str in the data member of the target object
    str=new char[1];
    str[0] = '\0';
}
//the function of pop_back
void String::pop_back()
{
    //Delete the last character of str in the data member of the target object
    char *p = str;
    while (*p != '\0')
        p++;
    p--;
    *p = '\0';
}
//Maybe we should use strrev...

char* &String::reverse()
{
    //Reverse str in the data member of the target object
    int first, last;
       first = 0;
       last = (int)strlen(str);
       while ((first != last) && (first != --last))
           std::swap(str[first++], str[last]);
    return str;
}
char *&String::ChineseReverse()
{
    //Reverse str（Chinese）in the data member of the target object
	long length = strlen(str), t = length;
    for (int i = 0; i < length / 2; i += 2, t -= 2)
    {
        int ret = str[i];
        str[i] = str[t - 2];
        str[t - 2] = ret;

        ret = str[i + 1];
        str[i + 1] = str[t - 1];
        str[t - 1] = ret;
    }
    return str;
}
/*char *&String::copy(const String &Str)
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
}*/
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

ostream &operator<<(ostream &out, const String &Str)
{
    out << Str.str;
    return out;
}

istream &operator>>(istream &in, String &Str)
{
    char str[1000];
    in >> str;
    Str = str; // 利用转换构造函数（自动转换），再利用赋值运算
    return in;
}

String operator+(const String &str1,const String &str2)
{
    String temp;
    temp.str=new char[strlen(str1.str)+strlen(str2.str)+1];
    strcpy(temp.str,str1.str);
    strcat(temp.str,str2.str);
    return temp;
}
String &String::operator+=(const String &Str) 
{
    *this = *this + Str;
    return *this;
}
char &String::operator[](int index) const
{
    return str[index];
}
void String::Show() const
{
    cout << str << endl;
}

char &String::front() const
{
    return str[0];
}
char &String::back() const
{
    return str[strlen(str) - 1];
}
char *String::c_str() const
{
    return str;
}
/*String String::chip(int start, int end, int step = 1) const
{
    String temp;
}*/
//test xcode again
