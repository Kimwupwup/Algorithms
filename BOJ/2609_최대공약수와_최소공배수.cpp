#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    if (a % b == 0)
        return b;
    return GCD(b, a % b);
}

int LCM(int a, int b)
{
    return (a * b) / GCD(a, b);
}

int main()
{
    int a, b;
    cin >> a >> b;
    cout << GCD(a, b) << endl;
    cout << LCM(a, b) << endl;
    return 0;
}