#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 101;
int n;
int cache[MAX];
vector<pair<int, int>> v;

int LIS()
{
    int idx = 0;
    int length = 0;
    cache[idx] = v[0].second;

    for (int i = 1; i < n; i++)
    {
        if (cache[idx] < v[i].second)
            cache[++idx] = v[i].second;
        else
        {
            int idx2 = lower_bound(cache, cache + idx, v[i].second) - cache;
            cache[idx2] = v[i].second;
            length++;
        }
    }
    return length;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    cout << LIS() << endl;
    return 0;
}