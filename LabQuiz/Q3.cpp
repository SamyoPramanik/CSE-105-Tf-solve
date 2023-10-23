// infix to postfix
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char c)
{
    if (c == '+')
        return 1;
    if (c == '-')
        return 2;
    if (c == '*')
        return 3;
    if (c == '/')
        return 4;
}

bool isNumber(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    return false;
}

string infixToPostfix(string infix)
{
    string postfix;
    stack<char> operand;
    for (int i = 0; i < infix.size(); i++)
    {
        if (isNumber(infix[i]))
            postfix += infix[i];

        else if (operand.empty())
            operand.push(infix[i]);
        else
        {
            while (operand.size() && ((operand.top()) >= precedence(infix[i])))
            {
                postfix += operand.top();
                operand.pop();
            }
            operand.push(infix[i]);
        }
    }

    if (operand.size())
        postfix += operand.top();

    return postfix;
}
int main()
{
    string infix;
    string postfix;

    cin >> infix;
    postfix = infixToPostfix(infix);

    cout << postfix << endl;
}