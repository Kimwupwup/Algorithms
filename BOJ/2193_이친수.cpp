#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 91;
int n;
pair<long long, long long> cache[MAX];

long long solution()
{
    cache[0] = {0, 0};
    cache[1] = {0, 1};
    cache[2] = {1, 0};
    for (int i = 3; i <= n; i++)
    {
        cache[i].first = cache[i - 1].second + cache[i - 1].first;
        cache[i].second = cache[i - 1].first;
    }
    return cache[n].first + cache[n].second;
}

int main()
{
    cin >> n;
    cout << solution() << endl;
    return 0;
}