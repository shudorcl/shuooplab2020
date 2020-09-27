#include "String.h"
#include <iostream>
using namespace std;

int main()
{
    int n;
    String test("Ark"), str,stra("Kamen Rider Ark One");
    str.copy(test);
    n=stra.find(test);
    cout << "Wait...\n"
         <<"n="<<n<<endl;
    return 0;
}
