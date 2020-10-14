#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

template <typename TYPE> class Vector
{
public:
    Vector(const TYPE &x = 0, const TYPE &y = 0);
    void Show() const
    {
        cout << '(' << a << ", " << b << ')';
    }
    TYPE &GetX();
    TYPE &GetY();
    TYPE &GetNorm();

private:
    TYPE a, b;
};



#endif
