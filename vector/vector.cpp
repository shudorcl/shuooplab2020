#include <iostream>
#include "vector.h"
using namespace std;
int main() {
    //测试构造函数
    Vector<double> v2(1,10);
    Vector<double> v4(1,9);
    Vector<double> v3(3,9);
    Vector<double> v1(3,10);
    Vector<double> v5(v1);//测试拷贝构造函数
    Vector <int> v9;
    cout<<v2;
    cout<<v2.module()<<endl;//测试module求模函数
    v2+=2;//测试+=
    cout<<v2;
    cout<<v2.module()<<endl;
    v2.normalize();//测试normalize单位化函数
    cout << v2;
  
    cout<<v2*v1;//测试向量相乘
    cout<<(v4!=v3)<<endl;//测试逻辑运算符函数
    cout<<v5.empty()<<endl;//测试empty函数
    v5=3+v1;//测试友元函数+
    cout<<v5;
    cout<<v9;
    return 0;
}
