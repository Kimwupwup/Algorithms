#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int matrix[MAX];
int cache[MAX];
int n;

int DP()
{
    for (int i = 1; i <= n; i++)
    {
        if (cache[i - 1] > 0)
            cache[i] = cache[i - 1] + matrix[i];
        else
            cache[i] = matrix[i];
    }
    int maxi = cache[1];
    for (int i = 2; i <= n; i++)
        maxi = max(maxi, cache[i]);
    return maxi;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> matrix[i];

    cout << DP() << endl;
    return 0;
}