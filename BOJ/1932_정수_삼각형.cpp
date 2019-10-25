#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> v;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<int> row;
        for (int j = 0; j < i + 1; j++)
        {
            int temp;
            cin >> temp;
            row.push_back(temp);
        }
        v.push_back(row);
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (j == 0)
                v[i][j] += v[i - 1][j];
            else if (j == v[i].size() - 1)
                v[i][j] += v[i - 1][j - 1];
            else
                v[i][j] += max(v[i - 1][j - 1], v[i - 1][j]);
        }
    }
    sort(v[n - 1].begin(), v[n - 1].end(), greater<int>());
    cout << v[n - 1][0] << endl;
}