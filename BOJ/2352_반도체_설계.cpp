#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 40001;
int n;
int matrix[MAX];
int cache[MAX];

int LIS()
{
    int idx = 1;
    cache[idx] = matrix[1];

    for (int i = 2; i <= n; i++)
    {
        if (cache[idx] < matrix[i])
            cache[++idx] = matrix[i];
        else
        {
            int idx2 = lower_bound(cache + 1, cache + idx + 1, matrix[i]) - cache;
            cache[idx2] = matrix[i];
        }
    }
    return idx;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> matrix[i];

    cout << LIS() << endl;
    return 0;
}