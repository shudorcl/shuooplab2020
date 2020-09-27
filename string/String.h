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
    String(const String &str);
    String(const String &str, int pos, int n);
    ~String() {}
    //String Function
    int String_length() const;
    int String_find(const String &str) const;
    void String_swap(String &str);
    void String_reverse(String &str);
    void String_uppercase(String &str);
    void String_lowercase(String &str);
    void String_copy(const String &str) const;
};
#endif //STRING_FUNCTION_STRING_HEAD_H
