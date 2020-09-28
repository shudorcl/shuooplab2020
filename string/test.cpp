#include "String.h"
#include <iostream>
using namespace std;

int main()
{
    String Empty, ZerOne("Zero one"), ArkOne("Ark One Rider", 7), Ark(10, 'A');
    String AAA = Ark;
    ZerOne.Show();
    ArkOne.Show();
    Ark.Show();
    AAA.Show();
    cout << "Zero One's length is " << ZerOne.length() << endl;
    String One("one");
    cout << "Find one in zero one:" << ZerOne.find(One)
         << "\nThen we'll copy ArkOne into Empty" << endl;
    Empty.ncopy(ArkOne, 3);
    Empty.Show();
    cout << "We'll contact Zero One and Ark" << endl;
    Empty.catenate(ZerOne);
    Empty.Show();
    cout << "Now it's time for operators."
         << "\nWe'll compare ArkOne and Zero One"
         << "\nArkOne>Zero One:" << (ArkOne > ZerOne) << endl;
    return 0;
}
