#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

const long long MAX = pow(2, 31) - 1;
vector<long long> have;
int k, n;

bool check(long long mid)
{
    int cnt = 0;
    for (int i = 0; i < k; i++)
        cnt += have[i] / mid;
    if (cnt >= n)
        return true;
    return false;
}
int main()
{
    cin >> k >> n;
    have.resize(k);
    for (int i = 0; i < k; i++)
        cin >> have[i];
    sort(have.begin(), have.end(), greater<int>());
    
    long long left = 1;
    long long right = have[0];
    long long ret = 0;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
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