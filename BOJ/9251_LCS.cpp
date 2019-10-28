#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 1001;
string a, b;
int cache[MAX][MAX];

int LCS()
{
    for (int i = 1; i <= a.size(); i++)
    {
        for (int j = 1; j <= b.size(); j++)
        {
            if (a[i - 1] == b[j - 1])
                cache[i][j] = cache[i - 1][j - 1] + 1;
            else
                cache[i][j] = max(cache[i - 1][j], cache[i][j - 1]);
        }
    }
    return cache[a.size()][b.size()];
}

int main()
{
    cin >> a >> b;

    cout << LCS() << endl;
}