#include "vector.h"
#include <iostream>
#include <cmath>
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
double &Vector::GetNorm()
{
    int sum = a * a + b * b;
    double res = sqrt(sum);
    return res;
}