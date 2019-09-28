#include <string>
#include <vector>
#include <memory.h>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int map[101][101];
    int cache[101][101];
    memset(map, 0, sizeof(map));

    for (vector<int> v : puddles) {
        map[v[1]][v[0]] = -1;
    }

    cache[1][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (map[i][j] == -1) cache[i][j] = 0;
            else cache[i][j] = (cache[i - 1][j] + cache[i][j - 1]) % 1000000007;
        }
    }
    return cache[n][m];
}

int main() {
    cout << solution(6, 3, {{2, 1}, {2, 2}, {4, 3}}) << endl;
}