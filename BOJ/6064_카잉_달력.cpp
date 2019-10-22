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
    int test;
    int m, n, x, y;

    cin >> test;

    for (int i = 0; i < test; i++)
    {
        cin >> m >> n >> x >> y;
        int maxYear = LCM(m, n);

        while (true)
        {
            if (x > maxYear || (x - 1) % n + 1 == y)
                break;
            x += m;
        }
        if (x > maxYear)
            cout << -1 << endl;
        else
            cout << x << endl;
    }
    return 0;
}