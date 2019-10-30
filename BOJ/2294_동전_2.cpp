#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAX = 10001;

int n, k;
int matrix[101];
int cache[MAX];

int solution()
{
    memset(cache, 0, sizeof(cache));
    for (int i = 1; i <= k; i++)
        cache[i] = MAX;

    for (int i = 1; i <= n; i++)
        for (int j = matrix[i]; j <= k; j++)
            cache[j] = min(cache[j], cache[j - matrix[i]] + 1);

    return cache[k] == MAX ? -1 : cache[k];
}

int main()
{

    cin >> n >> k;
    if (n < 1 || n > 100 || k < 1 || k >= MAX)
        exit(-1);
    for (int i = 1; i <= n; i++)
        cin >> matrix[i];
    cout << solution() << endl;
    return 0;
}