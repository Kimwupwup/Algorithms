#include <iostream>
#include <map>
using namespace std;
int main()
{
    map<int, int> m[2];
    int x, y;
    for (int i = 0; i < 3; i++)
    {
        cin >> x >> y;
        m[0][x] += 1;
        m[1][y] += 1;
    }
    for (int i = 0; i <= 1; i++)
        for (map<int, int>::iterator iter = m[i].begin(); iter != m[i].end(); iter++)
            if (iter->second == 1)
                cout << iter->first << " ";
}