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

String::String(const String &Str,int pos,int n)
{
    int i,m;
    m=(int)strlen(Str.str);
    if(pos>m)
    {
        str=new char[1];
        str[0]='\0';
        return;
    }
    if(m-pos<n)
        n=m-pos;
    if(n<0)
        n=0;
    str =new char[n+1];
    for(i=0;i<n;i++)
        str[i]=Str.str[pos+i];
    str[i]='\0';
}
String::~String()
{
    if(str!=NULL)
        delete [] str;
}
//the defination of append
String &String::append(const String &s)
{
    strcat(str, s.str);
    m_str += strlen(s.str);
    return *this;
}

String &String::append(const String &s, int pos, int n)
{
    //setting the begin and the end of the target
    char temp[100];
    int k = 0;
    for(int i = pos ;i < n ;i++)
    {
        temp[k] = s.str[i];
        k++;
    }
    strcat(str,temp);
    m_str += strlen(temp);
    return * this;
}

String & String::append(const char *s)
{
    strcat(str,s);
    m_str += strlen(s);
    return *this;
}

String &String::append(int pos, const char s)
{
    char p_temp[100];
    int i = 0;
    for(i = 0;i < pos ; i++)
    {
        p_temp[i] = s;
    }
    p_temp[i] = '\0';
    strcat(str, p_temp);
    m_str += strlen(p_temp);
    return *this;
}

//the functiong of the empty
bool String::empty() const
{
    if(str == NULL)
        return true;
    else
        return false;
}

//the function of insert
String & String::insert(int p0,const char *s)
{
    int n=(int)strlen(str);
    if(p0>n)
        p0=n;
    char *p=new char[strlen(str)+strlen(s)+1];
    strncpy(p,str,p0);
    p[p0]='\0';
    strcat(p,s);
    strcat(p,str+p0);
    delete [] str;
    str=p;
    return *this;
}

//the function of substr
String String::substr(int pos,int n) const
{
    String temp(*this,pos,n);
    return temp;
}
//the function of swap
String &String::swap(const char *s)
{
   char p_temp[100];
   int  size =(int)strlen(s);
   strcpy(p_temp,s);
   p_temp[size] = '\0';
   strcpy(str,p_temp);
   return * this;
}
String & String::swap(const String & s)
{
    char p_temp[100],g_temp[100];
    int size = (int)strlen(s.str);
    strcpy(p_temp, s.str);
    strcpy(g_temp,str);
    p_temp[size] = '\0';
    g_temp[m_str] ='\0';
    strcpy(str, p_temp);
    strcpy(s.str,g_temp);
    return *this;
}
//the function of clear
void String::clear(String &s)
{
    char *p=s.str;
    *p='\0';
}
//the function of pop_back
void String::pop_back(String &s)
{
    char *p=s.str;
    while(*p!='\0')
        p++;
    p--;
    *p='\0';
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
