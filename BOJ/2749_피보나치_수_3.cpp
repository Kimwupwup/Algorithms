#include <iostream>
#include <vector>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    if (n == 1 || n == 2)
    {
        cout << 1 << endl;
        return 0;
    }
    bool isFlip = false;
    int m1 = 1, m2 = 1;
    int cnt = 3;
    while (true)
    {
        if (isFlip)
            m1 = (m1 + m2) % 1000000;
        else
            m2 = (m1 + m2) % 1000000;
        isFlip = !isFlip;
        if (m1 == 1 && m2 == 1)
        {
            break;
        }
        cnt++;
    }

    n %= (cnt - 2);
    m1 = 1;
    m2 = 1;
    for (int i = 3; i <= n; i++)
    {
        if (isFlip)
            m1 = (m1 + m2) % 1000000;
        else
            m2 = (m1 + m2) % 1000000;
        if (i + 1 > n)
            cout << (isFlip ? m1 : m2) << endl;
        isFlip = !isFlip;
    }
}