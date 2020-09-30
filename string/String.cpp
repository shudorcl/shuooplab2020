#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

//the defination of construct function
String::String(const char *s)
{
    strs=new char[strlen(s)+1];
    strcpy(strs,s);
}

String::String(const char *s,int n)
{
    int i,m=(int)strlen(s);
    if(m<n)
        n=m;
    if(n<0)
        n=0;
    strs=new char[n+1];
    for(i=0;i<n;i++)
        strs[i]=s[i];
    strs[i]='\0';
}

String::String(int n,char c)
{
    int i;
    if(n<0)
        n=0;
    strs=new char[n+1];
    for(i=0;i<n;i++)
        strs[i]=c;
    strs[i]='\0';
}
String::String(const String &Str)
{
    strs =new char[strlen(Str.strs)+1];
    strcpy(strs,Str.strs);
}

String::String(const String &Str,int pos,int n)
{
    int i,m;
    m=(int)strlen(Str.strs);
    if(pos>m)
    {
        strs=new char[1];
        strs[0]='\0';
        return;
    }
    if(m-pos<n)
        n=m-pos;
    if(n<0)
        n=0;
    strs =new char[n+1];
    for(i=0;i<n;i++)
        strs[i]=Str.strs[pos+i];
    strs[i]='\0';
}
String::~String()
{
    if(strs!=NULL)
        delete [] strs;
}
//the defination of append
String &String::append(const String &s)
{
    strcat(strs, s.strs);
    m_str += strlen(s.strs);
    return *this;
}

String &String::append(const String &s, int pos, int n)
{
    //setting the begin and the lens of the target
    char temp[100];
    int k = 0;
    for(int i = pos ;i < n+pos ;i++)
    {
        temp[k] = s.strs[i];
        k++;
    }
    temp[k]='\0';
    strcat(strs,temp);
    m_str += strlen(temp);
    return * this;
}

String & String::append(const char *s)
{
    strcat(strs,s);
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
    strcat(strs, p_temp);
    m_str += strlen(p_temp);
    return *this;
}

//the functiong of the empty
bool String::empty() const
{
    if(strs[0] =='\0' )
        return true;
    else
        return false;
}

//the function of insert
String & String::insert(int p0,const char *s)
{
    int n=(int)strlen(strs);
    if(p0>n)
        p0=n;
    char *p=new char[strlen(strs)+strlen(s)+1];
    strncpy(p,strs,p0);
    p[p0]='\0';
    strcat(p,s);
    strcat(p,strs+p0);
    delete [] strs;
    strs=p;
    return *this;
}

//the function of substr
String String::substr(int pos,int n)
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
   strcpy(strs,p_temp);
   return * this;
}
String & String::swap(const String & s)
{
    char p_temp[100];
    int size = (int)strlen(s.strs);
    strcpy(p_temp, s.strs);
    p_temp[size] = '\0';
    strcpy(strs, p_temp);
    return *this;
}
//the function of clear
void String::clear()
{
    char *p=strs;
    *p='\0';
}
//the function of pop_back
void String::pop_back()
{
    char *p=strs;
    while(*p!='\0')
        p++;
    p--;
    *p='\0';
}
void String::reverse()
{
    int first, last;
    first = 0;
    last = (int)strlen(strs);
    while ((first != last) && (first != --last))
        std::swap(strs[first++], strs[last]);
}
