#include <iostream>
using namespace std;

int a, b, c;

long long partition(int ta, int tb, int tc)
{
    if (tb == 1)
        return ta;
    else
    {
        long long temp = partition(ta, tb / 2, tc) % tc;
        if (tb % 2 == 1)
            return ((temp * temp) % tc * ta) % tc;
        else
            return (temp * temp) % tc;
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> a >> b >> c;
    cout << partition(a % c, b, c) << endl;
    return 0;
}