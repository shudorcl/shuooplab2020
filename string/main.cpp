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
    cout<<"\n\n----------------------------------------------------CONSTRUCT----------------------------------------------"<<endl;
    cout<<"\nNo parameter structure: "<<endl;
    cout<<"---CODE---(String C1;)\n"<<endl;
    String C1;
    //cout<<"---------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    cout<<"\n------------------------------------------------CONVERTING CONSTRUCT---------------------------------------"<<endl;
    cout<<"\nParametric structure: "<<endl;
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"1.use the entered character as the value of Str of the data member\n of the target object: "<<endl;
    cout<<"---CODE---(String C2=\"nice to see you\";)\n"<<endl;
    String C2="nice to see you";
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"2.take n characters of the input string as the value of Str of the data member of the target object: "<<endl;
    cout<<"---CODE---(String C3(\"nice to see you all!\",16);)\n"<<endl;
    String C3("nice to see you all!",16);
    cout<<"\n$---CODE---(String C3r(\"nice to see you all!\",36);)\n"<<endl;
    String C3r("nice to see you all!",36);
	cout<<"---------------------------------------------------------------"<<endl;
    cout<<"3.repeat the input character n times as the value of Str of the data member of the target object: "<<endl;
    cout<<"---CODE---(String C4(10,'S');)\n"<<endl;
    String C4(10,'S');
	cout<<"---------------------------------------------------------------"<<endl;
    cout<<"4.take n characters from a certain position (pos) from the value of str in the data member of the reference\n object as the value of Str of the data member of the target object: "<<endl;
    cout<<"---CODE---(String C5(C4,5,5);)\n"<<endl;
    String C5(C4,5,5);
    cout<<"\n---CODE---(String C5r(C4,15,3);)\n"<<endl;
    String C5r(C4,15,3);
    cout<<"---CODE---(String C5s(C4,5,15);)\n"<<endl;
    String C5s(C4,5,15);
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
	//cout<<"---------------------------------------------------------------"<<endl;
	cout<<"\n----------------------------------------------------COPY---------------------------------------------------"<<endl;
    cout<<"\n5.use the value of str in the data member of the input object as the value of Str in the data member of the\n target object: "<<endl;
    cout<<"---CODE---(String C6(C4);)\n"<<endl;
    String C6(C4);
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    cout<<"\n--------------------------------------------------DESTRUCT-------------------------------------------------\n"<<endl;
}

void test2()
{
    cout<<"\n-------------------------------------------TEST ACCESS TO CLASS OBJECTS------------------------------------";
    cout<<"\n\n---------------------------------------------------LENGTH--------------------------------------------------\n"<<endl;
    cout<<"---CODE---(String L=\"LLLLLLLLENGTH\";)"<<endl;
    String L="LLLLLLLLENGTH";
    cout<<"\n---CODE---(L.length();)\n"<<endl;
    cout<<"the length of String L: "<<L.length()<<endl;
    //cout<<"--------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    cout<<"\n\n---------------------------------------------------FIND----------------------------------------------------"<<endl;
    cout<<"\n---CODE---(String F1=\"FIND\";)\n"<<endl;
    String F1="FIND";
    cout<<"\n---CODE---(String F2=\"N\";)\n"<<endl;
    String F2="N";
    cout<<"\n---CODE---(F1.find(F2))\n"<<endl;
    cout<<"Whether there is a character matching F2 in F1 and the Position: "<<F1.find(F2)<<endl;
	//cout<<"--------------------------------------------------------------"<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    cout<<"\n\n---------------------------------------------------RFIND---------------------------------------------------"<<endl;
    cout<<"\n---CODE---(String F3=\"RIGHT\";)\n"<<endl;
    String F3="RIGHT";
    cout<<"\n---CODE---(String F4=\"I\";)\n"<<endl;
    String F4="I";
    cout<<"\n---CODE---(F1.rfind(F2))\n"<<endl;
    cout<<"Whether there is a character matching F3 in F4 and the Position: "<<F3.find(F4)<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //test for empty
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n---------------------------------------------------EMPTY---------------------------------------------------"<<endl;
    cout<<"\n---CODE---(String s2= \"it is not empty!\";)\n"<<endl;
    String s2= "it is not empty!";
    cout<<s2.empty()<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(String s21;)\n"<<endl;
    String s21;
    cout<<s21.empty()<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n--------------------------------------------------DESTRUCT-------------------------------------------------\n"<<endl;
    //cout<<"\n\n------------------------------DESTRUCT----------------------------\n"<<endl;
}
void test3()
{
    cout<<"\n------------------------------------------STRING MODIFICATION OPERATION------------------------------------";
    cout<<"\n\n------------------------------------------------APPEND-----------------------------------------------------"<<endl;
    //test for append
    cout<<"---CODE---(String s1 = \"A\";)"<<endl;
    cout<<"---CODE---(String str2=\"BBBBBBBBBBBBBBB\";)\n"<<endl;
    String s1 = "A";
    String str2="BBBBBBBBBBBBBBB";
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(s1.append(\"CCCCCCCCCCCC\");)\n"<<endl;
    s1.append("CCCCCCCCCCCC");
    s1.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(s1.append(str2,6,3);)\n"<<endl;
    s1.append(str2,6,3);
    s1.Show();
    cout<<"---CODE---(String s1k = \"\")\n"<<endl;
    cout<<"---CODE---(s1k.append(str2,6,19);)\n"<<endl;
    //String s1k = "";
    s1.append(str2,6,19);
    s1.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(s1.append(str2);)\n"<<endl;
    s1.append(str2);
    s1.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(s1.append(4,\'C\');)\n"<<endl;
    s1.append(4,'C');
    s1.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-------------------------------------------------INSERT----------------------------------------------------"<<endl;
    //test for insert
    cout<<"---CODE---(String s3=\"position () for insert\";)\n"<<endl;
    String s3="position () for insert";
    cout<<"\n---CODE---(s3.insert(9,\"insert characters\");)\n"<<endl;
    s3.insert(9,"insert characters");
    cout<<"Insert the input character from a certain position (pos) of str in the data member of the target object: "<<endl;
    s3.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(String s3r=\"position () for insert\";)\n"<<endl;
    String s3r="position () for insert";
    cout<<"\n---CODE---(s3r.insert(199,\" insert characters\");)\n"<<endl;
    s3r.insert(199," insert characters");
    cout<<"Insert the input character from a certain position (pos) of str in the data member of the target object: "<<endl;
    s3r.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-------------------------------------------------SUBSTR----------------------------------------------------"<<endl;
    //cout<<"\n\n--------------------------SUBSTR-----------------------------------"<<endl;
    //test for substr
    cout<<"---CODE---(String s4=\"this is (SOMETHING) in the brackets\";)\n"<<endl;
    String s4="this is (SOMETHING) in the brackets";
    cout<<"\n---CODE---(String sub_str1=s4.substr(9,9);)\n"<<endl;
    String sub_str1=s4.substr(9,9);
    sub_str1.Show();
    cout<<"\n---CODE---(String sub_str2=s4.substr(9,39);)\n"<<endl;
    String sub_str2=s4.substr(9,39);
    sub_str2.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    //cout<<s4.substr(9,9).str<<endl;
    cout<<"\n\n-------------------------------------------------SWAP------------------------------------------------------"<<endl;
    //cout<<"\n\n---------------------------SWAP------------------------------------"<<endl;
    //test for swap
    cout<<"---CODE---(String s5=\"APPLE 1\";)\n"<<endl;
    String s5="APPLE 1";
    cout<<"\n---CODE---(s5.swap(\"APPLE 2\");)\n"<<endl;
    s5.swap("APPLE 2");
    s5.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"---CODE---(String s6=\"IDEA\";)\n"<<endl;
    String s6="IDEA";
    cout<<"\n---CODE---(s5.swap(s6);)\n"<<endl;
    s5.swap(s6);
    s5.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n------------------------------------------------CLEAR------------------------------------------------------"<<endl;
    //test for clear
    cout<<"---CODE---(String s7=\"Have I been cleaned up yet?\";)\n"<<endl;
    String s7="Have I been cleaned up yet?";
    cout<<"\n---CODE---(s7.clear();)\n"<<endl;
    s7.clear();
    //cout<<"---CODE---(s7.Show();)"<<endl;
    //s7.Show();
    cout<<"---CODE---(cout<<s7.empty()<<endl;)"<<endl;
    cout<<s7.empty()<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-----------------------------------------------POP_BACK----------------------------------------------------"<<endl;
    //test for pop_back
    cout<<"---CODE---(String s8=\"This is the last character--->k\";)\n"<<endl;
    String s8="This is the last character--->k";
    s8.Show();
    cout<<"\n---CODE---(s8.pop_back();)\n"<<endl;
    s8.pop_back();
    s8.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-----------------------------------------------RESERVE-----------------------------------------------------"<<endl;
    //test for reverse
    cout<<"---CODE---(String s9=\"please reverse me!\";)\n"<<endl;
    String s9="please reverse me!";
    cout<<"\n---CODE---(s9.reverse();)\n"<<endl;
    s9.reverse();
    s9.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-------------------------------------------CHINESE_RESERVE-------------------------------------------------"<<endl;
    //test for reverse
    cout<<"---CODE---(String s10=\"这句话被反转了吗？\";)\n"<<endl;
    String s10="这句话被反转了吗？";
    cout<<"\n---CODE---(s10.ChineseReverse();)\n"<<endl;
    s10.ChineseReverse();
    cout<<"？吗了转反被话句这"<<endl;
    //s10.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n--------------------------------------------------DESTRUCT-------------------------------------------------\n"<<endl;
    //cout<<"\n\n------------------------------DESTRUCT-----------------------------\n"<<endl;
}
void test4()
{
    cout<<"\n-------------------------------------------TEST OVERLOADED RELATIONAL OPERATORS------------------------------------";
    cout<<"\n\n--------------------------------------------TEST OPERATOR '=' ---------------------------------------------"<<endl;
    cout<<"---CODE---(String L1=\"Waiting to be copied\";)"<<endl;
    String L1="Waiting to be copied";
    cout<<"\n---CODE---(String L2=L1;)"<<endl;
    String L2=L1;
    cout<<endl;
    L2.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-------------------------------------------TEST OPERATOR '==' ---------------------------------------------"<<endl;
    cout<<"---CODE---(String L3=\"This is a normal string\";)"<<endl;
    String L3="This is a normal string";
    cout<<"\n---CODE---(String L4=\"This is a normal string\";)"<<endl;
    String L4="This is a normal string";
    cout<<"\n---CODE---(int Judge=(L3==L4);)"<<endl;
    int Judge=(L3==L4);
    cout<<"Judge: "<<Judge<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-------------------------------------------TEST OPERATOR '!=' ---------------------------------------------"<<endl;
    cout<<"---CODE---(String L5=\"This is a normal string\";)"<<endl;
    String L5="This is a normal string";
    cout<<"\n---CODE---(String L6=\"This isn't a normal string\";)"<<endl;
    String L6="This isn't a normal string";
    cout<<"\n---CODE---(int Judge=(L5!=L6);)"<<endl;
    Judge=(L5!=L6);
    cout<<"Judge: "<<Judge<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n--------------------------------------------TEST OPERATOR '>' ---------------------------------------------"<<endl;
    cout<<"---CODE---(String L7=\"This is a longlong string\";)"<<endl;
    String L7="This is a longlong string";
    cout<<"\n---CODE---(String L8=\"This isn't a short string\";)"<<endl;
    String L8="This isn't a short string";
    cout<<"\n---CODE---(int Judge=(L7>L8);)"<<endl;
    Judge=(L7>L8);
    cout<<"Judge: "<<Judge<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-------------------------------------------TEST OPERATOR '>=' ---------------------------------------------"<<endl;
    cout<<"---CODE---(String L9=\"This is a longlong string\";)"<<endl;
    String L9="This is a longlong string";
    cout<<"\n---CODE---(String L10=\"This isn't a short string\";)"<<endl;
    String L10="This isn't a short string";
    cout<<"\n---CODE---(int Judge=(L9>=L10);)"<<endl;
    Judge=(L9>=L10);
    cout<<"Judge: "<<Judge<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n--------------------------------------------TEST OPERATOR '<' ---------------------------------------------"<<endl;
    cout<<"---CODE---(String L11=\"This is a longlong string\";)"<<endl;
    String L11="This is a longlong string";
    cout<<"\n---CODE---(String L12=\"This isn't a short string\";)"<<endl;
    String L12="This isn't a short string";
    cout<<"\n---CODE---(int Judge=(L11<L12);)"<<endl;
    Judge=(L11<L12);
    cout<<"Judge: "<<Judge<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-------------------------------------------TEST OPERATOR '<=' ---------------------------------------------"<<endl;
    cout<<"---CODE---(String L13=\"This is a longlong string\";)"<<endl;
    String L13="This is a longlong string";
    cout<<"\n---CODE---(String L14=\"This isn't a short string\";)"<<endl;
    String L14="This isn't a short string";
    cout<<"\n---CODE---(int Judge=(L13<=L14);)"<<endl;
    Judge=(L13>=L14);
    cout<<"Judge: "<<Judge<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-------------------------------------------TEST OPERATOR '+' ----------------------------------------------"<<endl;
    cout<<"---CODE---(String L15=\"AAAAA\";)"<<endl;
    String L15="AAAAA";
    cout<<"\n---CODE---(String L16=\"BBBBB\";)"<<endl;
    String L16="BBBBB";
    cout<<"\n---CODE---(String L17(L15+L16);)"<<endl;
    String L17(L15+L16);
    L17.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n\n-------------------------------------------TEST OPERATOR '+=' ---------------------------------------------"<<endl;
    cout<<"---CODE---(String L18=\"AAAAA\";)"<<endl;
    String L18="AAAAA";
    cout<<"\n---CODE---(String L19=\"BBBBB\";)"<<endl;
    String L19="BBBBB";
    cout<<"\n---CODE---(L18+=L19;)"<<endl;
    L18+=L19;
    L18.Show();
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    cout<<"\n\n-------------------------------------------TEST OPERATOR '[]' ---------------------------------------------"<<endl;
    cout<<"---CODE---(String L18=\"AAAAA\";)"<<endl;
    String L20="ABCDE";
    cout<<"\n---CODE---(for(int i=0;i<L20.length();i++) cout<<\"L20[i] = \"<<L20[i]<<endl;)"<<endl;
    for(int i=0;i<L20.length();i++)
        cout<<"L20[i] = "<<L20[i]<<endl;
    //cout<<L20[1]<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------\n"<<endl;
    //cout<<"-------------------------------------------------------------------"<<endl;
    cout<<"\n--------------------------------------------------DESTRUCT-------------------------------------------------\n"<<endl;
    //cout<<"\n\n------------------------------DESTRUCT-----------------------------\n"<<endl;
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
        else if(n==4) test4();
    }
    return 0;
}
