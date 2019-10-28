#include <iostream>
#include <memory.h>
using namespace std;
int n;
int cache[101][10];
const int MOD = 1000000000;

int main()
{
    cin >> n;
    for (int i = 0; i < 10; i++)
        cache[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (j == 0)
                cache[i][0] = cache[i - 1][1] % MOD;
            else if (j == 9)
                cache[i][9] = cache[i - 1][8] % MOD;
            else
                cache[i][j] = (cache[i - 1][j - 1] + cache[i - 1][j + 1]) % MOD;
        }
    }
    int sum = 0;
    for (int i = 1; i < 10; i++)
        sum = (sum + cache[n][i]) % MOD;
    cout << sum << endl;
}