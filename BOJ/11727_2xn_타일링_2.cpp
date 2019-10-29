#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int n;
int cache[MAX];

int solution()
{
    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 3;
    for (int i = 3; i <= n; i++)
        cache[i] = (cache[i - 1] + cache[i - 2] * 2) % 10007;
    return cache[n];
}

int main()
{
    cin >> n;
    cout << solution() << endl;
    return 0;
}