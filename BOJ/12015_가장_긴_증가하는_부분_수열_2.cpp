#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int v[1000001];
int ret[1000001];
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    int idx = 0;
    ret[0] = v[0];
    for (int i = 1; i < n; i++)
    {
        if (v[i] > ret[idx])
            ret[++idx] = v[i];
        else
        {
            int idx2 = lower_bound(ret, ret + idx, v[i]) - ret;
            ret[idx2] = v[i];
        }
    }
    cout << idx + 1 << "\n";
    return 0;
}