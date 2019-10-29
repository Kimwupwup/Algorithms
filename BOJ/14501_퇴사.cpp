#include <iostream>
#include <algorithm>
#include <memory.h>
using namespace std;

const int MAX = 16;
const int INF = 987654321;
pair<int, int> quest[MAX];
int n;
int cache[MAX];

int solution(int day)
{
    if (day == n + 1)
        return 0;
    if (day > n + 1)
        return -INF;
    int &ret = cache[day];
    if (ret != -1)
        return ret;
    ret = 0;
    ret += max(quest[day].second + solution(quest[day].first + day), solution(day + 1));
    return ret;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> quest[i].first >> quest[i].second;
    }
    memset(cache, -1, sizeof(cache));
    cout << solution(1) << endl;
    return 0;
}