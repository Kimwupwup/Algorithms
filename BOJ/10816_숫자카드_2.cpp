#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> mp;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        mp[temp]++;
    }

    int m;
    vector<int> ret;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        ret.push_back(mp[temp]);
    }

    for (int a : ret)
        cout << a << " ";
    return 0;
}