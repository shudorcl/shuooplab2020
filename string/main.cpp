//
//  main.cpp
//  string
//
//  Created by SUNYIYAN on 2020/9/30.
//  Copyright  2020 SUNYIYAN. All rights reserved.
//


#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

void test1()
{
	cout<<"\n-------------------------------------------TEST THE FOUR BASIC FUNCTIONS-----------------------------------";
    cout<<"\n\n---------------------------CONSTRUCT---------------------------"<<endl;
    cout<<"\nNo parameter structure: "<<endl;
    cout<<"---CODE---(String C1;)\n"<<endl;
    String C1;
    cout<<"\n-----------------------CONVERTING CONSTRUCT--------------------"<<endl;
    cout<<"\nParametric structure: "<<endl;
    
    cout<<"\n1.use the entered character as the value of Str of the data member of the target object: "<<endl;
    cout<<"---CODE---(String C2=\"nice to see you\";)\n"<<endl;
    String C2="nice to see you";
    
    cout<<"\n2.take n characters of the input string as the value of Str of the data member of the target object: "<<endl;
    cout<<"---CODE---(String C3(\"nice to see you!\",16);)\n"<<endl;
    String C3("nice to see you!",16);
    cout<<"\n3.repeat the input character n times as the value of Str of the data member of the target object: "<<endl;
    cout<<"---CODE---(String C4(10,'S');)\n"<<endl;
    String C4(10,'S');
    cout<<"\n4.take n characters from a certain position (pos) from the value of str in the data member of the reference object as the value of Str of the data member of the target object: "<<endl;
    cout<<"---CODE---(String C5(C4,5,5);)\n"<<endl;
    String C5(C4,5,5);
	cout<<"\n------------------------------COPY------------------------------"<<endl;
    cout<<"\n5.use the value of str in the data member of the input object as the value of Str in the data member of the target object: "<<endl;
    cout<<"---CODE---(String C6(C4);)\n"<<endl;
    String C6(C4);
    cout<<"\n----------------------------DESTRUCT----------------------------\n"<<endl;
}

void test2()
{
    cout<<"\n-------------------------------------------TEST ACCESS TO CLASS OBJECTS------------------------------------";
    cout<<"\n\n--------------------------LENGTH--------------------------"<<endl;
    String L="LLLLLLLLENGTH";
    cout<<"\n---CODE---(L.length())\n"<<endl;
    cout<<"the length of String L: "<<L.length()<<endl;
    cout<<"\n---------------------------FIND---------------------------"<<endl;
    String F1="FIND";
    String F2="N";
    cout<<"\n---CODE---(F1.find(F2))\n"<<endl;
    cout<<"Whether there is a character matching F2 in F1 and the Position: "<<F1.find(F2)<<endl<<endl;
    String F3="RIGHT";
    String F4="I";
    cout<<"\n---CODE---(F1.rfind(F2))\n"<<endl;
    cout<<"Whether there is a character matching F3 in F4 and the Position: "<<F3.find(F4)<<endl;
    cout<<"\n--------------------------DESTRUCT------------------------\n"<<endl;
}
void test3()
{
    cout<<"\n-------------------------------------------TEST ACCESS TO CLASS OBJECTS------------------------------------";
    cout<<"\n\n--------------------------LENGTH--------------------------"<<endl;
    //test for append
    String s1 = "A ";
    String str2="BBBBBBBBBB ";
    cout<<"-------------------------------------------------------------------"<<endl;
    s1.append("AAAAAAAAAA ");
    s1.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    s1.append(str2,6,3);
    s1.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    s1.append(str2);
    s1.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    s1.append(4,'C');
    s1.Show();
    cout<<"\n-----------------------------------------------------------------------------------------------------------------------"<<endl;
    //test for empty
    String s2= "ffaffafafaaffaf";
    cout<<s2.empty()<<endl;
    String s21;
    cout<<s21.empty()<<endl;
    //test for insert
    String s3="wwwwwwwwwwwww";
    s3.insert(5,"testeeeee");
    s3.Show();
    //test for substr
    String s4="jjjjjjjjjjjjj";
    s4.substr(3,4);
    s4.Show();
    //cout<<s4.substr(3,4).str<<endl;
    //test for swap
    String s5="bbbbbbbbbb";
    String s6="cccccccccc";
    s5.swap("aaaaaaaaaaa");
    s5.Show();
    s5.swap(s6);
    s5.Show();
    //test for clear
    String s7="am i clear?";
    s7.clear();
    s7.Show();
    cout<<s7.empty()<<endl;
    //test for pop_back
    String s8="this is a temp word k";
    s8.Show();
    s8.pop_back();
    s8.Show();
    //test for reverse
    String s9="please reverse it";
    s9.reverse();
    s9.Show();
}
int main()
{
    int n;
    while(1)
    {
        cout<<"\n--------------------------------------------CLASS STRING FUNCTIONS TEST------------------------------------"<<endl;
        cout<<"[0] Quit"<<endl;
        cout<<"[1] Test the four basic functions"<<endl;
        cout<<"[2] Test access to class objects"<<endl;
        cout<<"[3] String modification operation"<<endl;
        cout<<"[4] Test overloaded relational operators"<<endl;
        cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
        cout<<"Please enter a number:";
        cin>>n;
        if(n==0) break;
        else if(n==1) test1();
        else if(n==2) test2();
        else if(n==3) test3();
        //else if(n==4) test04();
    }
    return 0;
}
