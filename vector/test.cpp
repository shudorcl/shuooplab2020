//
// Created by lenovo on 2020/10/18.
//
#include "vector.h"
using namespace std;
int main()
{
    Vector v1(3);
    Vector v2;
    v1.Show();
    v2.Show();
    Vector v3 = v2;
    v3.Show();
    Vector v4(100, 1);
    v4.Show();
    //v4.chip(0, 33, 2);
    v3.Show();
    return 0;
}

