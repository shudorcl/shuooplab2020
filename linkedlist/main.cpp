#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include "Linklist.h"
using namespace std;
class Book
{//创建数据类型->图书类
public:
    string name;
    int ID;
    explicit Book(string n="No Name",int id=0):name(std::move(n)),ID(id)
    {

    }
    friend ostream &operator<<(ostream& out,Book &book)
    {
        out<<setfill('0')<<setw(4)<<book.ID<<'\t'<<book.name<<'\t'<<endl;
        return  out;
    }
};
int main()
{
    LinkList<Book> list;
    Node<Book> node;
    string name;
    int id;
    while (1)
    {
        cout<<"=================\n"
            <<" 欢迎来到图书管理系统 \n"
            <<"请输入图书名称，回车退出"<<endl;
        getline(cin,name);
        if(name[0]=='\0')
        {
            cout<<"下次再见\n"
                <<"=================\n"<<endl;
            break;
        }
        cout<<"请输入图书编号："<<endl;
        cin>>id;
    }
    return 0;
}
