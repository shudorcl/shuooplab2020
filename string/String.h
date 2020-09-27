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
    ~String() {}
    //String Function
    int length() const;
    int find(const String &Str) const;
    void swap(String &Str);
    void reverse(String &Str);
    void uppercase(String &Str);
    void lowercase(String &Str);
    void copy(const String &Str) const;
};
#endif //STRING_FUNCTION_STRING_HEAD_H