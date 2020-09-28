#include "String.h"
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    String test("Ark"), str, stra("Kamen Rider Ark Zero-One");
    //str.copy(test);
    n = stra.find(test);
    m = stra.rfind(test);
    cout << "Wait...\n"
         << "n=" << n << "\n"
         << "m=" << m << endl;
    str.ncopy(test, 2);
    cout << "Wait...\n"
         << endl;
    cout <<(test==stra)<<endl;
    return 0;
}
