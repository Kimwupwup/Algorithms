#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    pair<int, int> p;
    vector<pair<int, int>> v;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p.first >> p.second;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    for (pair<int, int> temp : v)
        cout << temp.first << " " << temp.second << "\n";
    return 0;
}