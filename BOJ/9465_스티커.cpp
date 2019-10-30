#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 100001;
int t, n;
int matrix[3][MAX];
int cache[3][MAX];

int solution()
{
    cache[1][1] = matrix[1][1];
    cache[2][1] = matrix[2][1];
    cache[1][2] = matrix[1][2] + cache[2][1];
    cache[2][2] = matrix[2][2] + cache[1][1];
    for (int i = 3; i <= n; i++)
    {
        cache[1][i] = matrix[1][i] + max(cache[2][i - 1], cache[2][i - 2]);
        cache[2][i] = matrix[2][i] + max(cache[1][i - 1], cache[1][i - 2]);
    }
    return max(cache[1][n], cache[2][n]);
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        for (int j = 1; j < 3; j++)
            for (int k = 1; k <= n; k++)
                cin >> matrix[j][k];
        cout << solution() << endl;
    }
    return 0;
}