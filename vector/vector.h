#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

class Vector
{
public:
    Vector(const int &x = 0, const int &y = 0);
    void Show() const
    {
        cout << '(' << a << ", " << b << ')';
    }
    int &GetX();
    int &GetY();
    int &GetNorm();

private:
    int a, b;
};

#endif
