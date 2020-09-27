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
    int length() const;
    int find(const String &str) const;
    void swap(String &str);
    void reverse(String &str);
    void uppercase(String &str);
    void lowercase(String &str);
    void copy(const String &str) const;
};
#endif //STRING_FUNCTION_STRING_HEAD_H
