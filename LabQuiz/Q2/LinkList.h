#ifndef LINKLIST
#define LINKLIST
#include <iostream>
using namespace std;

template <class E>
class Node
{
public:
    E val;
    Node<E> *next;

    Node()
    {
        val = E();
        next = NULL;
    }

    Node(E val, Node<E> *next = NULL)
    {
        this->val = val;
        this->next = next;
    }

    E getVal()
    {
        return val;
    }
};

template <class E>
class LL
{
    Node<E> *head;
    Node<E> *cur;

public:
    LL()
    {
        head = new Node<E>();
        cur = head;
    }

    void insert(E val)
    {
        Node<E> *newNode = new Node<E>(val, cur->next);
        cur->next = newNode;
    }

    void append(E val)
    {
        insert(val);
        next();
    }

    E remove()
    {
        if (cur->next == NULL)
        {
            cout << "Nothing to remove" << endl;
            return E();
        }

        Node<E> *temp = cur->next;
        cur->next = temp->next;
        E val = temp->getVal();
    }

    void next()
    {
        if (cur->next == NULL)
        {
            cout << "at last element" << endl;
            return;
        }

        cur = cur->next;
    }

    void prev()
    {
        if (cur == head)
        {
            cout << "at first position" << endl;
        }

        Node<E> *temp = cur;
        cur = head;
        while (cur->next != temp)
        {
            cur = cur->next;
        }
    }

    void moveToFirst()
    {
        cur = head;
    }

    E getValue()
    {
        if (cur->next == NULL)
        {
            cout << "No value" << endl;
            return E();
        }

        return cur->next->getVal();
    }

    // find interesection of list
    void intersect(LL<E> &l1, LL<E> &l2)
    {
        l1.moveToFirst();
        l2.moveToFirst();

        while (l1.cur->next && l2.cur->next)
        {
            cout << "working" << endl;
            if (l1.getValue() == l2.getValue())
            {
                append(l1.getValue());
                l1.next();
                l2.next();
            }
            else if (l1.getValue() < l2.getValue())
                l1.next();
            else
                l2.next();
        }
    }

    void print()
    {
        moveToFirst();
        while (cur->next)
        {
            cout << getValue() << " ";
            next();
        }
        cout << endl;
    }
};

#endif