#include <iostream>
#include <algorithm>

using namespace std;

int countTwo(int a)
{
    int ret = 0;
    while (a != 0)
    {
        ret += a / 2;
        a /= 2;
    }
    return ret;
}

int countFive(int a)
{
    int ret = 0;
    while (a != 0)
    {
        ret += a / 5;
        a /= 5;
    }
    return ret;
}

int main()
{
    int n, m, a, b, c, aa, bb, cc;
    cin >> n >> m;
    a = countFive(n);
    b = countFive(m);
    c = countFive(n - m);

    aa = countTwo(n);
    bb = countTwo(m);
    cc = countTwo(n - m);

    cout << min((a - b - c), (aa - bb - cc)) << endl;
    return 0;
}