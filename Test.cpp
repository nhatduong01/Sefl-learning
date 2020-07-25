#include <iostream>
#include <string.h>
using namespace std;

class String
{
    char *str;

public:
    String(const char *s);
    String(const String &temp);
    void change(int index, char c) { str[index] = c; }
    char *get() { return str; }
};

String::String(const char *s)
{
    int l = strlen(s);
    str = new char[l + 1];
    strcpy(str, s);
}
String::String(const String &temp)
{
    int size = strlen(temp.str);
    this->str = new char[size];
    strcpy(this->str, temp.str);
}
int f(int x, int &c)
{
    c = c - 1;
    if (c == 0)
        return 1;
    x = x + 1;
    return f(x, c) * x;
}
int main()
{
    int p = 5;
    cout << f(p, p) << endl;
    system("pause");
    return 0;
}