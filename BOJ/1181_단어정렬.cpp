#include <iostream>
#include <set>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    pair<int, string> p;
    set<pair<int, string>> v;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.insert({str.size(), str});
    }
    set<pair<int, string>>::iterator iter;
    for (iter = v.begin(); iter != v.end(); iter++)
        cout << iter->second << "\n";
    return 0;
}