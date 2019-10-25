#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    pair<pair<int, int>, string> p;
    vector<pair<pair<int, int>, string>> v;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> p.first.first >> p.second;
        p.first.second = i;
        v.push_back(p);
    }
    sort(v.begin(), v.end());
    for (pair<pair<int, int>, string> temp : v)
        cout << temp.first.first << " " << temp.second << "\n";
    return 0;
}