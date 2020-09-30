//
//  main.cpp
//  string
//
//  Created by SUNYIYAN on 2020/9/30.
//  Copyright © 2020 SUNYIYAN. All rights reserved.
//


#include <iostream>
#include <cstring>
#include "String.h"

using namespace std;

int main()
{
    //test for append
    String s1 = "ababaaabg";
    cout << s1.strs << endl;
    String str2="printjjjjjjjjjjj";
    s1.append("Writing ");      // "Writing "
    cout<<s1.strs<<endl;
    s1.append(str2,6,3);        // "10 "
    cout<<s1.strs<<endl;
    s1.append(str2);
    cout<<s1.strs<<endl;
    s1.append(5,'w');
    cout<<s1.strs<<endl;
    //test for empty
    String s2= "ffaffafafaaffaf";
    cout<<s2.empty()<<endl;
    String s21;
    cout<<s21.empty()<<endl;
    //test for insert
    String s3="wwwwwwwwwwwww";
    s3.insert(5,"testeeeee");
    cout<<s3.strs<<endl;
    //test for substr
    String s4="jjjjjjjjjjjjj";
    cout<<s4.substr(3,4).strs<<endl;
    //test for swap
    String s5="bbbbbbbbbb";
    String s6="cccccccccc";
    s5.swap("aaaaaaaaaaa");
    cout<<s5.strs<<endl;
    s5.swap(s6);
    cout<<s5.strs<<endl;
    //test for clear
    String s7="am i clear?";
    s7.clear();
    cout<<s7.strs<<endl;
    cout<<s7.empty()<<endl;
    //test for pop_back
    String s8="this is a temp word k";
    cout<<s8.strs<<endl;
    s8.pop_back();
    cout<<s8.strs<<endl;
    //test for reverse
    String s9="please reverse it";
    s9.reverse();
    cout<<s9.strs<<endl;
    return 0;
}
