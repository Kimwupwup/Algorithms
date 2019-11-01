#include <iostream>
#include <algorithm>
#include <math.h>
#include <memory.h>

using namespace std;

const int MAX = 100001;
int cache[MAX];

int solution(int n)
{
    memset(cache, 0, sizeof(cache));
    for (int i = 1; i <= n; i++)
        cache[i] = MAX;

    for (int i = 1; i <= sqrt(n); i++)
    {
        for (int j = i * i; j <= n; j++)
        {
            cache[j] = min(cache[j], cache[j - (i * i)] + 1);
        }
    }
    return cache[n];
}

int main()
{
    int n;

    cin >> n;
    cout << solution(n) << endl;
    return 0;
}