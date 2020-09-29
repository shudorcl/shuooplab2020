#ifndef STRING_FUNCTION_STRING_HEAD_H
#define STRING_FUNCTION_STRING_HEAD_H
using namespace std;

class String
{
private:
    char *strp;
    int m_str;//the length of the String
public:
    char *str;
    String(const char *s = "");
    String(const char *s, int n);
    String(int n, char c);
    String(const String &Str);
    String(const String &Str, int pos, int n);
    ~String();
    
    //String Function
    //workingspace for sunyiyan
    //the defination of append
    String& append(const String &s);
    String& append(const String &s,int pos,int n);
    String& append(const char * s);
    String& append(int pos , const char s);
    //the functiong of the empty
    bool empty() const;
    //the function of insert
    String & insert(int p0,const char *s);
    String & insert(int idx,const string& str,int str_idx,int str_num);
    String & insert(int __pos, const char* __s,int __n);
    //the function of the substr
    String substr(int pos,int n) const;
    //the function of swap
    String & swap(const char * s);
    String & swap(const String & s);
    //the function of clear
    void clear(String &s);
    //the function of pop_back
    void pop_back(String &s);
    //the function of reverse
    void reverse(String &s);
};
#endif //STRING_FUNCTION_STRING_HEAD_H



