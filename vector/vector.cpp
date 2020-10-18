#include "vector.h"
#include <cmath>
#include <iostream>
using namespace std;

Vector::Vector(int vdim)
    : nums(new double(vdim)), size(vdim)
{
    //分配内存
    //初始化，并记录size
    for (int i = 0; i < vdim; i++)
        nums[i] = 0;
}
Vector::Vector(int vdim, double prim)
    : nums(new double(vdim)), size(vdim)
{
    for (int i = 0; i < vdim; i++)
        nums[i] = prim;
}
Vector::Vector(Vector &ov)
{
    /*if (nums!=NULL)
    {
        delete[] nums;
        nums = NULL;
    }*/
    nums = new double(ov.size);
    //赋值，并记录size
    for (int i = 0; i < ov.size; i++)
        nums[i] = ov.nums[i];
    size = ov.size;
}
Vector::~Vector()
{
    if(nums)
        delete[] nums;
    nums = NULL;
}
double Vector::Modular()
{
    double sum;
    for (int i = 0; i < size; i++)
    {
        sum += pow((nums[i]), 2);
    }
    return sqrt(sum);
}
void Vector::Show() const
{
    cout << '[';
    for (int i = 0; i < size; i++)
        {
            if(i!=size-1)
                cout << nums[i] << ',';
            else
                cout << nums[i] << ']' << endl;
        }
}