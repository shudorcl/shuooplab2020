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
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"1.use the entered character as the value of Str of the data member of the target object: "<<endl;
    cout<<"---CODE---(String C2=\"nice to see you\";)\n"<<endl;
    String C2="nice to see you";
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"2.take n characters of the input string as the value of Str of the data member of the target object: "<<endl;
    cout<<"---CODE---(String C3(\"nice to see you!\",16);)\n"<<endl;
    String C3("nice to see you!",16);
	cout<<"---------------------------------------------------------------"<<endl;
    cout<<"3.repeat the input character n times as the value of Str of the data member of the target object: "<<endl;
    cout<<"---CODE---(String C4(10,'S');)\n"<<endl;
    String C4(10,'S');
	cout<<"---------------------------------------------------------------"<<endl;
    cout<<"4.take n characters from a certain position (pos) from the value of str in the data member of the reference object as the value of Str of the data member of the target object: "<<endl;
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
    cout<<"\n\n----------------------------LENGTH-----------------------------\n"<<endl;
    String L="LLLLLLLLENGTH";
    cout<<"\n---CODE---(L.length())\n"<<endl;
    cout<<"the length of String L: "<<L.length()<<endl;
    cout<<"--------------------------------------------------------------"<<endl;
    cout<<"\n\n-----------------------------FIND-----------------------------\n"<<endl;
    String F1="FIND";
    String F2="N";
    cout<<"\n---CODE---(F1.find(F2))\n"<<endl;
    cout<<"Whether there is a character matching F2 in F1 and the Position: "<<F1.find(F2)<<endl;
	cout<<"--------------------------------------------------------------"<<endl;
    cout<<"\n\n-----------------------------RFIND----------------------------"<<endl;
    String F3="RIGHT";
    String F4="I";
    cout<<"\n---CODE---(F1.rfind(F2))\n"<<endl;
    cout<<"Whether there is a character matching F3 in F4 and the Position: "<<F3.find(F4)<<endl;
    //test for empty
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n---------------------------EMPTY-----------------------------------"<<endl;
    String s2= "it is not empty!";
    cout<<s2.empty()<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    String s21;
    cout<<s21.empty()<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n------------------------------DESTRUCT----------------------------\n"<<endl;
}
void test3()
{
    cout<<"\n-------------------------------------------STRING MODIFICATION OPERATION------------------------------------";
    cout<<"\n\n--------------------------APPEND-----------------------------------"<<endl;
    //test for append
    cout<<"---CODE---(String s1 = \"A\";)"<<endl;
    cout<<"---CODE---(String str2=\"BBBBBBBBBBBBBBB\";)\n"<<endl;
    String s1 = "A";
    String str2="BBBBBBBBBBBBBBB";
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(s1.append(\"CCCCCCCCCCCC\");)\n"<<endl;
    s1.append("CCCCCCCCCCCC");
    s1.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(s1.append(str2,6,3);)\n"<<endl;
    s1.append(str2,6,3);
    s1.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(s1.append(str2);)\n"<<endl;
    s1.append(str2);
    s1.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(s1.append(4,\'C\');)\n"<<endl;
    s1.append(4,'C');
    s1.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n--------------------------INSERT-----------------------------------"<<endl;
    //test for insert
    cout<<"---CODE---(String s3=\"position () for insert\";)\n"<<endl;
    String s3="position () for insert";
    cout<<"\n---CODE---(s3.insert(9,\"insert characters\");)\n"<<endl;
    s3.insert(9,"insert characters");
    cout<<"Insert the input character from a certain position (pos) of str in the data member of the target object: "<<endl;
    s3.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n--------------------------SUBSTR-----------------------------------"<<endl;
    //test for substr
    cout<<"---CODE---(String s4=\"this is (SOMETHING) in the brackets\";)\n"<<endl;
    String s4="this is (SOMETHING) in the brackets";
    cout<<"\n---CODE---(String s40=s4.substr(9,9);)\n"<<endl;
    String sub_str=s4.substr(9,9);
    sub_str.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    //cout<<s4.substr(9,9).str<<endl;
    cout<<"\n\n---------------------------SWAP------------------------------------"<<endl;
    //test for swap
    cout<<"---CODE---(String s5=\"APPLE 1\";)\n"<<endl;
    String s5="APPLE 1";
    cout<<"\n---CODE---(s5.swap(\"APPLE 2\");)\n"<<endl;
    s5.swap("APPLE 2");
    s5.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(String s6=\"IDEA\";)\n"<<endl;
    String s6="IDEA";
    cout<<"\n---CODE---(s5.swap(s6);)\n"<<endl;
    s5.swap(s6);
    s5.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n---------------------------CLEAR-----------------------------------"<<endl;
    //test for clear
    cout<<"---CODE---(String s7=\"Have I been cleaned up yet?\";)\n"<<endl;
    String s7="Have I been cleaned up yet?";
    cout<<"\n---CODE---(s7.clear();)\n"<<endl;
    s7.clear();
    //cout<<"---CODE---(s7.Show();)"<<endl;
    //s7.Show();
    cout<<"---CODE---(cout<<s7.empty()<<endl;)"<<endl;
    cout<<s7.empty()<<endl;
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-------------------------POP_BACK----------------------------------"<<endl;
    //test for pop_back
    cout<<"---CODE---(String s8=\"This is the last character--->k\";)\n"<<endl;
    String s8="This is the last character--->k";
    s8.Show();
    cout<<"\n---CODE---(s8.pop_back();)\n"<<endl;
    s8.pop_back();
    s8.Show();
    cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n---------------------------RESERVE---------------------------------"<<endl;
    //test for reverse
    cout<<"---CODE---(String s9=\"please reverse me!\";)\n"<<endl;
    String s9="please reverse me!";
    cout<<"\n---CODE---(s9.reverse();)\n"<<endl;
    s9.reverse();
    s9.Show();
    cout<<"\n\n------------------------------DESTRUCT-----------------------------\n"<<endl;
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
