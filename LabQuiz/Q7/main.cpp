#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
    BST<int, int> tree1;

    tree1.insert(8, 8);
    tree1.printInOrder();
    tree1.insert(4, 8);
    tree1.printInOrder();
    tree1.insert(12, 8);
    tree1.printInOrder();
    tree1.insert(2, 8);
    tree1.printInOrder();
    tree1.insert(6, 8);
    tree1.printInOrder();
    tree1.insert(10, 8);
    tree1.printInOrder();
    tree1.insert(14, 8);
    tree1.printInOrder();

    cout << "List:" << endl;
    LL<int, int> list = tree1.convertToList();
    list.print();

    // cout << "removing" << endl;
    // tree1.remove(8);
    // tree1.printInOrder();
    // tree1.remove(4);
    // tree1.printInOrder();
    // tree1.remove(12);
    // tree1.printInOrder();
    // tree1.remove(2);
    // tree1.printInOrder();
    // tree1.remove(6);
    // tree1.printInOrder();
    // tree1.remove(10);
    // tree1.printInOrder();
    // tree1.remove(14);
    // tree1.printInOrder();
}