#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

class Vector
{
public:
    Vector(int vdim=1);
    Vector(int vdim, double prim);
    Vector(Vector &ov);
    Vector &operator=(Vector &ov);
    virtual ~Vector();
    void Show() const;
    double Modular();

private:
    double *nums;
    int size;
};

#endif
