#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 10001;
int n;
int matrix[MAX];
int cache[MAX];
int answer[MAX];

int solution()
{
    int ret = 0;
    for (int i = 1; i <= n; i++)
    {
        cache[i] = matrix[i];
        for (int j = 1; j <= i; j++)
        {
            if (matrix[i] > matrix[j] && cache[i] < cache[j] + matrix[i])
                cache[i] = cache[j] + matrix[i];
            ret = max(ret, cache[i]);
        }
    }
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> matrix[i];
    cout << solution() << endl;
    return 0;
}