#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long n, m;
vector<long long> v;

bool check(long long mid)
{
    long long cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] - mid > 0)
            cnt += v[i] - mid;
    }
    if (cnt >= m)
        return true;
    return false;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];

    sort(v.begin(), v.end(), greater<long long>());
    long long right = v[0];
    long long left = 0;
    long long ret = 0;

    while (left <= right)
    {
        long long mid = (right + left) / 2;
        if (check(mid))
        {
            if (ret < mid)
                ret = mid;
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    cout << ret << "\n";
    return 0;
}