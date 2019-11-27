#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;
int n, m;

bool check(int mid)
{
    int cnt = 1;
    int prev = v[0];
    for (int i = 1; i < n; i++)
    {
        if (prev - v[i] >= mid)
        {
            cnt++;
            prev = v[i];
        }
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
    sort(v.begin(), v.end(), greater<int>());

    int left = 1;
    int right = v[0] - 1;
    int ret = 0;
    while (left <= right)
    {
        int mid = (left + right) / 2;
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