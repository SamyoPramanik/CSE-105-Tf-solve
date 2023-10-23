#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
    stack<int> st;
    queue<int> qu;

    int first = 0, second = 1;
    st.push(0);
    st.push(1);
    qu.push(0);
    qu.push(1);
    int n;
    cin >> n;

    for (int i = 0; i < n - 2; i++)
    {
        int current = first + second;
        first = second;
        second = current;
        st.push(current);
        qu.push(current);
    }

    cout << "print in order:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << qu.front() << " ";
        qu.pop();
    }
    cout << endl;

    cout << "print in reverse order:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;
}
