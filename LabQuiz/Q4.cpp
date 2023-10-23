#include <iostream>
using namespace std;

int decimalToOctal(int n)
{
    int k = 1;
    int octal = 0;

    while (n > 0)
    {
        octal += (n % 8) * k;
        n /= 8;
        k *= 10;
    }

    return octal;
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;

        int o = decimalToOctal(n);
        cout << o << endl;
    }
}