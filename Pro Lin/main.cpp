//
//  main.cpp
//  Pro Lin
//
//  Created by SUNYIYAN on 2020/11/10.
//  Copyright © 2020 SUNYIYAN. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <string>
#include <utility>
#include "LinkList.h"
using namespace std;

class Book
{//创建数据类型->图书类
public:
    string name;
    int ID;
    Book(string n="No Name",int id=0):name(n),ID(id)
    {}
    friend ostream &operator<<(ostream& out,Book &book)
    {
        out<<setfill('0')<<setw(4)<<book.ID<<'\t'<<book.name<<'\t'<<endl;
        return out;
    }
};
int main()
{
    Book book1("BravoDragon", 1), book2("LionSeki", 2), book3("LampDoAlangina", 3);
    Book bookarray[3]={book1,book2,book3};
    LinkList<Book> list(3,bookarray);
    string name, correct_name;
    char choose;
    int id, correct_id;
    cout<<"=================\n"
        <<"Welcome to the library management system, press Enter to exit\n"<<endl;
    while (1)
    {
        cout<<"List of books:"<<endl;
        list.ShowList();
        cout<<"What do you need? (1 add book. 2 borrow book. 3 book title check id. 4id check book title. 5 errata.)"<<endl;
        if(choose=='\0')
        {
        else if(choose=='1') {
            cout << "Please enter the book name: " << endl;
            cin >> name;
            cout << "Please enter the book number: " << endl;
            cin >> id;
            if(list.Locate(name,true)==NULL&&list.Locate_id(id,true)==NULL){
                cout<<"Already have this book"<<endl;
                continue;
            }
            Book new_book(name,id);
            list.Append(new_book);
            cout << "bibliography " + name + " Has been stored, the id of the book is: " << id;
        }
        else if(choose=='2'){
            cout << "Enter 1 book name to borrow the book, enter 2id to borrow the book" << endl;
            cin>>choose;
            if (choose=='1'){
                cout << "Please enter the title: " << endl;
                cin >> name;
                if(not list.Duplicate_name(name)){
                    cout<<"No such book found."<<endl;
                    continue;
                }
                list.NameDelete(name);
            }
            else if (choose=='2'){
                cout << "Please enter id:" << endl;
                cin >> id;
                if(not list.Duplicate_id(id)){
                    cout<<"No such book found."<<endl;
                    continue;
                }
                list.IDDelete(id);
            }
            else{
                cout << "I suspect that you have a problem here." <<endl;
            }
        }
        else if(choose=='3'){
            cout<<"Please enter the title:"<<endl;
            cin>>name;
            cout << "The id of this book is: "<< list.FindId(name)<<endl;
        }
        else if (choose=='4'){
            cout<<"Please enter id"<<endl;
            cin>>id;
            cout << "This book is titled: " + list.FindName(id)<<endl;
        }
        else if (choose=='5'){
            cout <<"What type of errata? 1id Errata 2 Title Errata"<<endl;
            cin >> choose;
            if (choose=='1'){
                cout << "Please enter the book title and original id: "<<endl;
                cin >> name >> id;
                cout << "Please enter the correct id: "<<endl;
                cin >> correct_id;
                list.ChangeId(name, id, correct_id);
            }
            if (choose=='2'){
                cout << "Please enter the original title and id: "<<endl;
                cin >> name >> id;
                cout << "Please enter the correct title: "<<endl;
                cin >> correct_name;
                list.ChangeName(name, id, correct_name);
            }
        }

    }
    return 0;
}
