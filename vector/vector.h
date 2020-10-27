//
// Created by wyh on 2020/10/22.
//

#ifndef XIANGMUSHIYAN_VECTOR_H
#define XIANGMUSHIYAN_VECTOR_H
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
template <typename T>
class Vector{
private:
    T *num;
    int size;
public:
    //构造函数和析构函数
    Vector(int vdim=1);
    Vector(T para,int vdim);
    Vector(const Vector &ve);
    virtual ~Vector();
    //功能
    bool empty()const;//判断空向量
    T module()const;//求模长
    void normalize();//单位化
    //运算符的重载
    Vector operator+(const Vector<T> &ve)throw(int);//向量与向量相加
    Vector operator+(const T s);
    friend Vector operator+(const T s,Vector<T> &ve){return ve+s;}//+友元函数
    Vector operator-(const Vector<T> &ve);
    Vector & operator+=(Vector<T> &ve)throw(int);
    Vector & operator+=(const T s);
    Vector & operator=(const Vector<T> & ve);
    bool operator!=(const Vector<T> &ve);
    bool operator==(const Vector<T> &ve);
    Vector operator*(const Vector<T> &ve)throw(int);
    Vector operator*(const T s);
    friend Vector operator*(const T s,Vector<T>&ve)
    {
        return ve*s;
    }
    Vector & operator*=(const T n);
    T operator[](const int index)throw(int);
    friend ostream & operator<<(ostream &out,const Vector<T> &ve)//重载输出流
    {
        out<<"[ ";
        for(int i=0;i<ve.size;i++)
            if(i<ve.size-1)
                out<<ve.num[i]<<",";
            else
                out<<ve.num[i];
        out<<" ]"<<endl;
        return out;
    }
};

template <typename T>
Vector<T>::Vector(int vdim) :num(new T[size]),size(vdim)//构造一个默认初始化为0的向量
{
    for(int i=0;i<vdim;i++)
        num[i]=0;
}
template <typename T>
Vector<T>::Vector(T para, int vdim):num(new T[vdim]),size(vdim)//带默认值的向量
{
    for(int i=0;i<size;i++)
        num[i]=para;
}
template <typename T>
Vector<T>::Vector(const Vector<T> &ve)//拷贝构造
{
    num=new T[ve.size];
    size=ve.size;
    for(int i=0;i<ve.size;i++)
        num[i]=ve.num[i];
}

template <typename T>
Vector<T>::~Vector()
{
    if(num!=NULL)delete []num;
    cout<<"Destruction succeed! "<<endl;
}

//运算符重载

template<typename T>
Vector<T> Vector<T>::operator+(const Vector<T> & ve)throw(int)//重载+运算符-向量相加
{
        if(this->size!=ve.size)
            throw 1;
        Vector<T> sum(size);
        for(int i=0;i<this->size;i++) {
            sum.num[i]=this->num[i] + ve.num[i];
        }
        return sum;

}
template <typename T>
Vector<T> Vector<T>::operator+(const T s)//重载向量与数相加
{
    Vector<T> sum(size);
    for(int i=0;i<size;i++)
        sum.num[i]=this->num[i]+s;
    return sum;
}

template <typename T>
Vector<T> & Vector<T>::operator+=(Vector<T> &ve)throw(int)//重载向量+=向量
{

    if(this->size!=ve.size)
        throw (int)1;
    for(int i=0;i<this->size;i++)
        this->num[i]=this->num[i]+ve.num[i];
    return *this;

}
template <typename T>
Vector<T> & Vector<T>::operator+=(const T s)//重载向量+=数值
{
    for(int i=0;i<size;i++)
        this->num[i]=this->num[i]+s;
    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator*(const Vector<T> &ve) throw(int)//重载点乘
{
    if(this->size!=ve.size)
        throw (int)1;
    Vector<T> mul(size);
    for(int i=0;i<size;i++)
    {
        mul.num[i]=this->num[i]*ve.num[i];
    }
    return mul;
}
template <typename T>
Vector<T> Vector<T>::operator*(const T s)//重载向量*一个数值
{
    Vector<T> mul(size);
    for(int i=0;i<size;i++)
        mul.num[i]=this->num[i]*s;
    return mul;
}

template <typename T>
Vector<T> & Vector<T>::operator*=(const T n)//重载向量*=向量
{
    for(int i=0;i<size;i++)
        this->num[i]=this->num[i]*n;
    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator-(const Vector<T> &ve)//重载-
{
    return *this+ve*(-1);
}

template <typename T>
T Vector<T>::operator[](const int index)throw(int )//重载[]
{
    if (index < 0 || index > this->size)
        throw (int)1;
    return this->num[index];

}

template <typename T>
bool Vector<T>::operator==(const Vector<T> &ve)//重载==
{
    if(this->size!=ve.size)
        return false;
    for(int i=0;i<size;i++)
        if(this->num[i]!=ve.num[i])
            return false;
    return true;
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T> &ve)//重载!=
{
    if(*this==ve)
        return false;
    else
        return true;
}

template <typename T>
Vector<T> & Vector<T>::operator=(const Vector<T> &ve)//深赋值
{
    if(&ve!=this)
    {
        if(this->num)delete []num;
        this->num=new T[ve.size];
        for(int i=0;i<size;i++)
            this->num[i]=ve.num[i];
        this->size=ve.size;
        return *this;
    }
    else
        return *this;
}


//功能
template <typename T>
T Vector<T>::module() const//求模长
{
    T sum=0;
    for(int i=0;i<this->size;i++)
        sum+=this->num[i]*this->num[i];
    return sqrt(sum);
}

template <typename T>
void Vector<T>::normalize()//向量单位化
{
    T denominator=this->module();
    for(int i=0;i<this->size;i++)
        this->num[i]=this->num[i]/denominator;
}

template <typename T>
bool Vector<T>::empty() const//判断是否为空向量
{
    if(this->size==0)
        return true;
    else
        return false;
}


#endif //XIANGMUSHIYAN_VECTOR_H
