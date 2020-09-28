#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;
//the defination of construct function
String::String(const char *s)
{
    str=new char[strlen(s)+1];
    strcpy(str,s);
}

String::String(const char *s,int n)
{
    int i,m=(int)strlen(s);
    if(m<n)
        n=m;
    if(n<0)
        n=0;
    str=new char[n+1];
    for(i=0;i<n;i++)
        str[i]=s[i];
    str[i]='\0';
}

String::String(int n,char c)
{
    int i;
    if(n<0)
        n=0;
    str=new char[n+1];
    for(i=0;i<n;i++)
        str[i]=c;
    str[i]='\0';
}
String::String(const String &Str)
{
    str =new char[strlen(Str.str)+1];
    strcpy(str,Str.str);
}

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
