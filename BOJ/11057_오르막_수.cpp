#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int n;
int cache[MAX][10];

int solution()
{
    for (int i = 0; i < 10; i++)
        cache[1][i] = i + 1;
    for (int i = 1; i <= n; i++)
        cache[i][0] = 1;

    for (int i = 2; i <= n; i++)
        for (int j = 1; j < 10; j++)
            cache[i][j] = (cache[i - 1][j] + cache[i][j - 1]) % 10007;
    return cache[n][9];
}

int main()
{
    cin >> n;
    cout << solution() << endl;
    return 0;
}