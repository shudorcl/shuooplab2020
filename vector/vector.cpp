#include "vector.h"
#include <iostream>
using namespace std;

Vector::Vector(const int &x, const int &y)
{
    a = x;
    b = y;
}
int &Vector::GetX()
{
    return a;
}
int &Vector::GetY()
{
    return b;
}