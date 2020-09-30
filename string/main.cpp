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
    s1.Show();
    String str2="printjjjjjjjjjjj";
    s1.append("Writing ");      // "Writing "
    s1.Show();
    s1.append(str2,6,3);        // "10 "
    s1.Show();
    s1.append(str2);
    s1.Show();
    s1.append(5,'w');
    s1.Show();
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
    return 0;
}
