#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    pair<int, int> p;
    vector<pair<int, int>> v;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p.second >> p.first;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    for (pair<int, int> temp : v)
        cout << temp.second << " " << temp.first << "\n";
    return 0;
}