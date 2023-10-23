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
    l1.append(6);

    LL<int> l2;
    l2.append(2);
    l2.append(4);
    l2.append(6);
    l2.append(8);

    LL<int> l3;
    l3.intersect(l1, l2);

    l1.print();
    l2.print();
    l3.print();
}