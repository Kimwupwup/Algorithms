#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

map<string, int> mp;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        mp[temp] = 1;
    }

    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string temp;
        cin >> temp;
        if (mp.find(temp) == mp.end())
            cout << 0 << "\n";
        else
            cout << 1 << "\n";
    }
}