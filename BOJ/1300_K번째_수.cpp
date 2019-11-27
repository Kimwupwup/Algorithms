#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    int left = 1;
    int right = m;
    int ret = 0;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += min(mid / i, n);
        if (cnt >= m)
        {
            right = mid - 1;
            ret = mid;
        }
        else
            left = mid + 1;
    }
    cout << ret << "\n";
    return 0;
}