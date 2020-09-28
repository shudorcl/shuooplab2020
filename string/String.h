#ifndef STRING_FUNCTION_STRING_HEAD_H
#define STRING_FUNCTION_STRING_HEAD_H
using namespace std;

class String
{
private:
    char *str;
    int m_str;//the length of the String
public:
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
    String& append(const char * test);
    String& append(int pos , const char test);
    //the functiong of the empty
    bool empty() const;
    //the function of insert
    String & insert(int p0,const char *s);
    String & insert();
    //the function of the substr
    String substr(int pos,int n) const;
    
};
#endif //STRING_FUNCTION_STRING_HEAD_H



