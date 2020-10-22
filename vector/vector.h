#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
using namespace std;

class Vector
{
public:
    Vector(int vdim=1);
    Vector(int vdim, double prim);
    Vector(const Vector &ov);
    Vector &operator=(const Vector &ov);
    virtual ~Vector();

    double Modular() const;//求模
    Vector& Normalize();//转换为单位向量
    Vector& Transposition();//向量前后转置
    double index(int index = 0);//获得指定位置成员,默认第一个
    double pop(int index = -1); //获取一个成员并弹出,默认最后一个
    Vector& append(double new_double); //在末尾加上成员
    Vector& insert(int index, double new_double);//在指定位置插入成员
    Vector chip(int start, int end, int step=1);//获得指定部分和步长的切片,默认全部，步长默认为1
    //太难了呜呜呜
    //重载运算符
    Vector operator+(Vector &ov);
    Vector operator-(Vector &ov);
    Vector &operator+=(Vector &ov);
    bool operator!=(Vector &ov);
    friend ostream &operator<<(ostream &out, const Vector &ov);
    friend istream &operator>>(istream &in, Vector &ov);
    bool operator==(Vector &ov);
    double operator*(Vector &ov);
    Vector operator*(double mult);
    double operator[](int index);
    void Show() const;

private:
    double *nums;
    int size;
};

#endif
