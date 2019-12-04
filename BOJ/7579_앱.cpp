/**
 * 백준 7579번 - 앱
 * i 번 앱은 m 바이트를 차지한다. 비활성화 후 활성화할 때, 드는 비용을 c
 * c 를 최소화하는 방식을 구현해야 한다.
 * 
 * TODO:
 * N 개 앱, 필요한 메모리 M
 * 
 * */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int const MAX = 100;
int N, M;
int memory[MAX];
int cost[MAX];
int dp[MAX][10001];

int max_memory (int idx, int total_cost) {
    if (idx >= MAX)
        return 0;
    
    int &ret = dp[idx][total_cost];

    if (ret != -1)
        return ret;
    
    ret = max_memory (idx + 1, total_cost);

    if (cost[idx] <= total_cost) {
        ret = max(ret, memory[idx] + max_memory (idx + 1, total_cost - cost[idx]));
    }
    return ret;
}

int main () {
    cin.tie (NULL);
    ios::sync_with_stdio (false);

    memset(dp, -1, sizeof(dp));

    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> memory[i];
    for (int i = 0; i < N; i++)
        cin >> cost[i];
    
    int total_cost = 0;
    while (true) {
        if (max_memory (0, total_cost) >= M) {
            cout << total_cost << "\n";
            break;
        }
        total_cost++;
    }
    return 0;
}