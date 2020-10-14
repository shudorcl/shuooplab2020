#include <iostream>
#include "vector.h"
using namespace std;
template <typename TYPE>
Vector<TYPE>::Vector(const TYPE &x, const TYPE &y)
{
    a = x;
    b = y;
}
template <typename TYPE> TYPE & Vector<TYPE>::GetX()
{
    return a;
}
template <typename TYPE> TYPE & Vector<TYPE>::GetY()
{
    return b;
}