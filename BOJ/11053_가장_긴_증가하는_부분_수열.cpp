#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
int matrix[MAX];
int cache[MAX];
int n;

int LIS()
{
    int idx = 0;
    cache[idx] = matrix[0];
    for (int i = 1; i < n; i++)
    {
        if (cache[idx] < matrix[i])
            cache[++idx] = matrix[i];
        else
        {
            int idx2 = lower_bound(cache, cache + idx, matrix[i]) - cache;
            cache[idx2] = matrix[i];
        }
    }
    return idx + 1;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> matrix[i];

    cout << LIS() << endl;
    return 0;
}