#include <iostream>
#include <queue>
using namespace std;

void reverse(queue<int> &q)
{
    queue<int> helperQ;
    while (q.size())
    {
        helperQ.push(q.front());
        q.pop();
    }

    while (helperQ.size())
    {
        for (int i = 1; i < helperQ.size(); i++)
        {
            helperQ.push(helperQ.front());
            helperQ.pop();
        }
        q.push(helperQ.front());
        helperQ.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverse(q);

    for (int i = 0; i < 5; i++)
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}