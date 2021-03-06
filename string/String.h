#ifndef STRING_FUNCTION_STRING_HEAD_H
#define STRING_FUNCTION_STRING_HEAD_H
#include <iostream>
#include <string.h>
using namespace std;

class String
{
private:
    char *str;
    int m_str; //the length of the String
public:
    //char *str;
    String(const char *s = "");
    String(const char *s, unsigned long n) throw(int);
    String(int n, char c);
    String(const String &Str);
    String(const String &Str, int pos, int n) throw(int);
    virtual ~String();

    //String Function
    //workingspace for sunyiyan
    //the defination of append
    String &append(const String &s);
    String &append(const String &s, unsigned long pos, unsigned long n)throw(int);
    String &append(const char *s);
    String &append(int num, const char s);
    //the functiong of the empty
    bool empty() const;
    //the defination of insert
    String &insert(int pos, const char *s) throw(int);
    //the defination of the substr
    String substr(int pos, int n) throw(int);
    //the function of swap
    String &swap(char *s);
    String &swap(const String &s);
	//String &swap(String &s);
    //the defination of clear
    void clear();
    //the defination of pop_back
    void pop_back();
    //the defination of reverse
    void Show() const;
    //String &operator=(const String &Str);
    //String Function rcl
    unsigned long length() const;
    unsigned long size() const;
	long find(const String &Str) const;
	long rfind(const String &Str) const;
    char *&reverse();
    char *&ChineseReverse();
    void uppercase(String &Str);
    void lowercase(String &Str);
    /*char *&copy(const String &Str);
    char *&ncopy(const String &Str, int n);
    char *&catenate(const String &Str);
    char *&ncatenate(const String &Str, int n);
     */
    char *c_str() const;
    String &operator=(const String &Str);
    friend String operator+(const String &Str1, const String &Str2);
    String &operator+=(const String &Str);
    friend bool operator==(const String &Str1, const String &Str2);
    friend bool operator!=(const String &Str1, const String &Str2);
    friend bool operator>(const String &Str1, const String &Str2);
    friend bool operator>=(const String &Str1, const String &Str2);
    friend bool operator<(const String &Str1, const String &Str2);
    friend bool operator<=(const String &Str1, const String &Str2);
    friend ostream &operator<<(ostream &out, const String &Str);
    friend istream &operator>>(istream &in, String &Str);
    char &operator[](int index) const;
    char &front() const;
    char &back() const;
    String chip(int start, int end, int step = 1) const;
};
#endif //STRING_FUNCTION_STRING_HEAD_H
//
//
