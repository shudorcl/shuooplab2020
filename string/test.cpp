#include "String.h"
#include <iostream>
using namespace std;

int main()
{
    int n, m;
    String test("Ark"), str, stra("Kamen Rider Ark One");
    str.copy(test);
    n = stra.find(test);
    m = stra.rfind(test);
    cout << "Wait...\n"
         << "n=" << n << "\n"
         << "m=" << m << endl;
    return 0;
}
