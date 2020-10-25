//
// Created by wyh on 2020/10/22.
//

#include "vector.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
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
Vector<T> Vector<T>::operator+(const Vector<T> & ve)//重载+运算符-向量相加
{
    try{
        if(this->size!=ve.size)
            throw 1;
        Vector<T> sum(size);
        for(int i=0;i<this->size;i++) {
            sum.num[i]=this->num[i] += ve.num[i];
        }
        return sum;
    } catch (int) {
            cout<<"The sizes of two vectors are different! "<<endl;//异常处理
    }
}
template <typename T>
Vector<T> Vector<T>::operator+(T &s)//重载向量与数相加
        {
            Vector<T> sum(size);
            for(int i=0;i<size;i++)
                sum.num[i]=this->num[i]+s;
            return sum;
        }

template <typename T>
Vector<T> & Vector<T>::operator+=(Vector<T> &ve)//重载向量+=向量
        {
            for(int i=0;i<this->size;i++)
                this->num[i]=this->num[i]+ve.num[i];
            return *this;
        }
template <typename T>
Vector<T> & Vector<T>::operator+=(T &s)//重载向量+=数值
        {
            for(int i=0;i<size;i++)
                this->num[i]=this->num[i]+s;
            return *this;
        }

template <typename T>
Vector<T> Vector<T>::operator*(const Vector<T> &ve)//重载向量对应元素*
{
    try{
        if(this->size!=ve.size)
            throw 1;
        Vector<T> mul(size);
        for(int i=0;i<size;i++)
        {
            mul.num[i]=this->num[i]*ve.num[i];
        }
        return mul;
    }catch(int){
        cout<<"This sizes of two vectors are different! "<<endl;
    }
}
template <typename T>
Vector<T> Vector<T>::operator*(T &s)//重载向量*一个数值
{
    Vector<T> mul(size);
    for(int i=0;i<size;i++)
        mul.num[i]*mul.num[i]*s;
    return mul;
}

template <typename T>
Vector<T> & Vector<T>::operator*=(const T &n)//重载向量*=向量
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
T Vector<T>::operator[](int index)//重载[]
{
    try{
        if(index<0||index>this->size)
            throw 1;
        return this->num[index];
    }catch(int ){
        cout<<"Index is out of boundary! "<<endl;
    }
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
ostream &operator<<(ostream &out,const Vector<T> &ve)//重载输出流
{
    out<<"[ ";
    for(int i=0;i<ve.size;i++)
        out<<" , "<<ve.num[i];
    out<<" ]"<<endl;
    return out;
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
    T sum;
    for(int i=0;i<size;i++)
        sum+=this->num[i];
    return sqrt(sum);
}

template <typename T>
void Vector<T>::normalize()//向量单位化
{
    T denominator=this->module();
    for(int i=0;i<size;i++)
        this->num[i]/=denominator;
}

template <typename T>
T Vector<T>::get(int i)//对应序号的值
{
    try{
        if(i>size||i<0)
            throw 1;
        else
            return this->num[i];
    }catch(int){
        cout<<"the index you input is out of the boundary! "<<endl;
    }
}

template <typename T>
T Vector<T>::pop(int i)//取出最后一个位置的值，并从向量中去除
{
    try {
        if (this->nums == NULL)//
            throw 1;
        double last = this->nums[this->size - 1];//与储存最后一个成员
        double *new_nums = new double(this->size - 1);//重新申请内存空间
        for (int i = 0; i < this->size - 1; i++)//拷贝数据
        {
            new_nums[i] = this->nums[i];
        }
        //指向新内存空间，内存拷贝，再删除new_nums
        delete[] num;
        num = new double(this->size - 1);
        memcpy(num, new_nums, this->size);
        delete new_nums;
        //最后更新size
        this->size--;
        return last;
    } catch (int ) {
        cout<<"the vector is empty! "<<endl;
    }
}

template <typename T>
bool Vector<T>::empty() const//判断是否为空向量
{
    if(this->size==0)
        return false;
    else
        return true;
}

template <typename T>
void Vector<T>::append(T in)//在末尾添加向量
{
    //申请新空间
    auto *new_nums = new T[this->size + 1];
    //拷贝数据
    int i;
    for ( i = 0; i < this->size; i++)
    {
        new_nums[i] = this->nums[i];
    }
    new_nums[i+1] = in;
    //指向新内存空间，内存拷贝，再删除new_nums
    delete[] num;
    num = new T[i+1];
    memcpy(num, new_nums, i+1);
    delete []new_nums;
    //最后更新size
    this->size++;
}
template <typename T>
void Vector<T>::insert(int index, T in)//在指定位置插入值
{
    auto *new_num=new T[this->size+1];
    int i;
    for(i=0;i<size+1;i++)
    {
        if(i==index)
            new_num[i]=in;
            i++;
        new_num[i]=this->num[i];
    }
    delete []num;
    num=new T[i+1];
    memcpy(num,new_num,i+1);
    delete [] new_num;
    this->size++;
}
