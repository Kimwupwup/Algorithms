#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 12;
int n, t;
int cache[MAX];

int solution()
{
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;
    cache[3] = 4;
    for (int i = 4; i <= n; i++)
    {
        cache[i] = cache[i - 1] + cache[i - 2] + cache[i - 3];
    }
    return cache[n];
}

int main()
{
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << solution() << endl;
    }

    return 0;
}