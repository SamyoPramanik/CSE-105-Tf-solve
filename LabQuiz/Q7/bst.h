#ifndef BINARYSEARCHTREE
#define BINARYSEARCHTREE
#include <iostream>
using namespace std;
template <class K, class E>
class Node
{
public:
    Node<K, E> *left, *right;
    typedef Node<K, E> ND;
    K key;
    E val;

    Node()
    {
        left = NULL;
        right = NULL;
    }
    Node(K key, E val, ND *left = NULL, ND *right = NULL)
    {
        this->key = key;
        this->val = val;
        this->right = right;
        this->left = left;
    }

    ~Node()
    {
        // delete left;
        // delete right;
        // left = NULL;
        // right = NULL;
    }
};

template <class K, class E>
class LL
{

public:
    typedef Node<K, E> ND;
    ND *head, *tail;

    LL(ND *head = NULL, ND *tail = NULL)
    {
        this->head = head;
        this->tail = tail;
    }

    void print()
    {
        ND *cur = head;
        cur = cur->right;
        while (cur != tail)
        {
            cout << cur->key << " ";
            cur = cur->right;
        }
        cout << endl;
    }
};

template <class K, class E>
class BST
{
    typedef Node<K, E> ND;
    ND *root;

    ND *insertHelp(ND *curNode, K key, E val)
    {
        if (curNode == NULL)
        {
            curNode = new ND(key, val);
            return curNode;
        }

        if (key < curNode->key)
            curNode->left = insertHelp(curNode->left, key, val);
        else
            curNode->right = insertHelp(curNode->right, key, val);

        return curNode;
    }

    ND *removeHelp(ND *curNode, K key)
    {
        if (key == curNode->key)
        {
            if (curNode->left && curNode->right)
            {
                ND *min = findMin(curNode->right);
                curNode->key = min->key;
                curNode->val = min->val;
                curNode->right = removeMin(curNode->right);
            }

            else if (curNode->left)
            {
                ND *temp = curNode;
                curNode = temp->left;
                // delete temp;
            }

            else
            {
                ND *temp = curNode;
                curNode = temp->right;
                // delete temp;
            }

            return curNode;
        }

        else if (key < curNode->key)
            curNode->left = removeHelp(curNode->left, key);
        else
            curNode->right = removeHelp(curNode->right, key);

        return curNode;
    }

    ND *findHelp(ND *curNode, K key)
    {
        if (key == curNode->key)
            return curNode;
        if (key < curNode->key)
            return findHelp(curNode->left, key);
        return findHelp(curNode->right, key);
    }

    ND *findMin(ND *curNode)
    {
        if (curNode->left == NULL)
            return curNode;

        return findMin(curNode->left);
    }

    ND *removeMin(ND *curNode)
    {
        if (curNode->left == NULL)
        {
            ND *temp = curNode->right;
            delete curNode;
            return temp;
        }

        curNode->left = removeMin(curNode->left);
        return curNode;
    }

    void printInOrderHelp(ND *curNode)
    {
        if (curNode == NULL)
            return;

        printInOrderHelp(curNode->left);
        cout << curNode->key << " ";
        printInOrderHelp(curNode->right);
    }

    void printHelp(ND *curNode)
    {
        if (curNode == NULL)
            return;

        if (curNode->left == NULL && curNode->right == NULL)
        {
            cout << curNode->key;
            return;
        }
        cout << curNode->key << "(";
        printHelp(curNode->left);
        cout << ",";
        printHelp(curNode->right);
        cout << ")";
    }

    LL<K, E> convertToListHelp(ND *curNode)
    {
        LL<K, E> l, r;

        if (curNode->left == NULL && curNode->right == NULL)
        {
            ND *head = new ND();
            ND *tail = new ND();
            curNode->left = head;
            curNode->right = tail;
            head->right = curNode;
            tail->left = curNode;
            return LL<K, E>(head, tail);
        }

        if (curNode->left && curNode->right)
        {
            l = convertToListHelp(curNode->left);
            r = convertToListHelp(curNode->right);
            ND *temp = l.tail;
            curNode->left = temp->left;
            temp->left->right = curNode;
            delete temp;

            temp = r.head;
            curNode->right = temp->right;
            r.head->left = curNode;
            delete temp;

            return LL<K, E>(l.head, r.tail);
        }

        if (curNode->left)
        {
            l = convertToListHelp(curNode->left);
            curNode->right = l.tail;
            curNode->left = l.tail->left;
            l.tail->left->right = curNode;
            l.tail->left = curNode;
            return LL<K, E>(l.head, l.tail);
        }

        if (curNode->right)
        {
            r = convertToListHelp(curNode->right);
            curNode->left = r.head;
            curNode->right = r.head->right;
            r.head->right->left = curNode;
            r.head->right = curNode;
            return LL<K, E>(r.head, r.tail);
        }
    }

public:
    BST()
    {
        root = NULL;
    }

    void insert(K key, E val)
    {
        root = insertHelp(root, key, val);
    }

    E findVal(K key) {}

    E remove(K key)
    {
        ND *node = findHelp(root, key);
        E val = node->val;
        root = removeHelp(root, key);
        return val;
    }

    void printInOrder()
    {
        // printInOrderHelp(root);
        printHelp(root);
        cout << endl;
    }

    LL<K, E> convertToList()
    {
        LL<K, E> list = convertToListHelp(root);
        return list;
    }
};

#endif