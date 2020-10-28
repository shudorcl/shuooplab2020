#include <iostream>
#include "vec.h"
using namespace std;
int main() {
    //测试构造函数
    Vector<double> v1(1.5,10);
    Vector<double> v2(3,10);
    Vector<int>v3(0);//空向量
    Vector<int>v4(5);//空向量
    Vector<int>v5(v4);//空向量
    cout<<v5;
    cout<<v1<<v2;//测试重载输出流
    cout<<v1+v2;//测试重载+
    cout<<v1*v2;//测试重载叉乘
    cout<<(-1)*v2;//测试友元函数
    cout<<v2-v1;//测试重载-
    cout<<(v1==v2)<<endl;//测试重载逻辑运算符
    cout<<v2.empty()<<endl;//测试判断空向量函数
    v2.normalize();//向量单位化
    cout<<v2<<endl;
    v2+=2;//测试迭代运算符
    cout<<v2<<endl;
    cout<<v2[8]<<endl;//测试重载[]
    cout<<v2.module()<<endl;//求模长
    cout<<v3.empty()<<endl;//判断空向量测试
    v3.vdimup(3);//测试向量升维
    cout<<v3;
    v3.vdimdown(1);//测试向量降维
    cout<<v3;
    cout<<v1.multiply(v2)<<endl;//测试点乘
    cout<<v1.angle(v2)<<"angle"<<endl;//测试角度计算
    return 0;
}
