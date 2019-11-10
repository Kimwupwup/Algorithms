#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

int t;
int n;
map<string, int> m;

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        m.clear();
        cin >> n;
        for (int j = 0; j < n; j++)
        {
            string name, type;
            cin >> name >> type;
            m[type]++;
        }

        int ret = 1;
        for (map<string, int>::iterator iter = m.begin(); iter != m.end(); iter++)
            ret *= (iter->second + 1);

        cout << ret - 1 << endl;
    }
    return 0;
}