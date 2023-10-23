#include <iostream>
#include "LinkList.h"
using namespace std;

int main()
{
    LL<int> l1;
    l1.append(1);
    l1.append(2);
    l1.append(3);
    l1.append(4);
    l1.append(5);
    l1.append(6);
    l1.append(7);
    l1.append(8);
    l1.append(9);
    l1.append(10);

    l1.print();
    int val = l1.getNodevalue(5);
    cout << val << endl;
}