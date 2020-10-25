//
// Created by wyh on 2020/10/22.
//

#ifndef XIANGMUSHIYAN_VECTOR_H
#define XIANGMUSHIYAN_VECTOR_H
#include <iostream>
#include <string>
using namespace std;
template <typename T>
class Vector{
private:
    T *num;
    int size;
public:
    //构造函数和析构函数
    Vector(){}
    Vector(int vdim=1);
    Vector(T para,int vdim);
    Vector(const Vector &ve);
    virtual ~Vector();
    //功能
    bool empty()const;//判断空向量
    T module()const;//求模长
    void normalize();//单位化
    T get(int i=0);//获得指定位置成员,默认第一个
    T pop(int i=-1);//取出指定位置成员，默认最后一个
    void append(T in);//在末尾添加元素
    void insert(int index,T in);//在指定位置添加元素
    //运算符的重载
    Vector operator+(const Vector<T> &ve);
    Vector operator+(T &s);
    friend Vector operator+(T &s,const Vector<T> &ve){return ve+s;}
    Vector operator-(const Vector<T> &ve);
    Vector & operator+=(Vector<T> &ve);
    Vector & operator+=(T &s);
    Vector & operator=(const Vector<T> & ve);
    bool operator!=(const Vector<T> &ve);
    bool operator==(const Vector<T> &ve);
    Vector operator*(const Vector<T> &ve);
    Vector operator*(T &s);
    friend Vector operator*(T &s,const Vector<T>&ve){return ve*s;}
    Vector & operator*=(const T &n);
    T operator[](int index);
    friend ostream & operator<<(ostream &out, const Vector<T> &ve);
};

#endif //XIANGMUSHIYAN_VECTOR_H
