#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n;
    vector<pair<pair<int, int>, int>> v;

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first.first >> v[i].first.second;
        v[i].second = 1;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (v[i].first.first < v[j].first.first && v[i].first.second < v[j].first.second)
                v[i].second++;
        }
    }
    for (pair<pair<int, int>, int> p : v)
        cout << p.second << " ";
    return 0;
}