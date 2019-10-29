#include <iostream>
#include <algorithm>
#include <memory.h>

using namespace std;

const int MAX = 101;
int n, k;
int cache[100001];
pair<int, int> pack[MAX];

int solution()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = k; j >= 1; j--)
        {
            if (pack[i].first <= j)
                cache[j] = max(cache[j], cache[j - pack[i].first] + pack[i].second);
        }
    }
    return cache[k];
}
int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> pack[i].first >> pack[i].second;
    cout << solution() << endl;
}