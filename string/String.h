#ifndef STRING_FUNCTION_STRING_HEAD_H
#define STRING_FUNCTION_STRING_HEAD_H
class String
{
private:
    char *str;

public:
    String(const char *s = "");
    String(const char *s, int n);
    String(int n, char c);
    String(const String &Str);
    String(const String &Str, int pos, int n);
    String &operator=(const String &Str);
    virtual ~String(); //
    //String Function
    int length() const;
    int find(const String &Str) const;
    int rfind(const String &Str) const;
    void swap(String &Str);
    void reverse(String &Str);
    void uppercase(String &Str);
    void lowercase(String &Str);
    char *&copy(const String &Str);
    char *&ncopy(const String &Str, int n);
    char *&catenate(const String &Str);
    char *&ncatenate(const String &Str, int n);
    friend bool operator==(const String &Str1, const String &Str2);
    friend bool operator!=(const String &Str1, const String &Str2);
    friend bool operator>(const String &Str1, const String &Str2);
    friend bool operator>=(const String &Str1, const String &Str2);
    friend bool operator<(const String &Str1, const String &Str2);
    friend bool operator<=(const String &Str1, const String &Str2);
    void Show() const;
};
#endif //STRING_FUNCTION_STRING_HEAD_H
//xhange
//sunyiyan.change
//haoye
