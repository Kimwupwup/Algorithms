#include <iostream>
#include <map>

using namespace std;
int n, input, i, j;
map<int, int> m;
int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> input;
        m[input] += 1;
    }
    for (map<int, int>::iterator iter = m.begin(); iter != m.end(); iter++)
    {
        for (i = 0; i < iter->second; i++)
            cout << iter->first << "\n";
    }
    return 0;
}