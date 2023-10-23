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

    E getNodevalue(int fraction)
    {
        moveToFirst();
        Node<E> *temp = cur->next;
        E ans = getValue();
        next();

        bool reachedLast = false;
        while (true)
        {
            for (int i = 0; i < fraction; i++)
            {
                temp = temp->next;
                if (temp == NULL)
                {
                    reachedLast = true;
                    break;
                }
            }

            if (reachedLast == false)
            {
                ans = getValue();
                next();
            }
            else
                break;
        }
        return ans;
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