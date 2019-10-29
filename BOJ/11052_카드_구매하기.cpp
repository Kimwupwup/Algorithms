#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int matrix[MAX];
int cache[MAX];
int n;

int solution()
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cache[i] = max(cache[i], matrix[j] + cache[i - j]);
    return cache[n];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> matrix[i];

    cout << solution() << endl;
    return 0;
}