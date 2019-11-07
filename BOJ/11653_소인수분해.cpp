#include <iostream>
using namespace std;
int n;
int main()
{
    cin >> n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << endl;
            n /= i;
            i--;
        }
    }

    if (n > 1)
        cout << n << endl;

    return 0;
}