/**
 * 백준 1516번 - 게임 개발
 * 
 * */
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 501;
int time[MAX], ret[MAX], degree[MAX];
int N;
vector<int> matrix[MAX];
queue<pair<int, int>> q;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        int temp;
        cin >> time[i];

        while (true) {
            cin >> temp;
            if (temp == -1) break;
            matrix[temp].push_back(i);
            degree[i]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            q.push({i, time[i]});
            ret[i] = time[i];
        }
    }

    while (!q.empty()) {
        int cur = q.front().first;
        int cost = q.front().second;
        q.pop();

        for (int i = 0; i < matrix[cur].size(); i++) {
            int next = matrix[cur][i];
            int next_cost = cost + time[next];

            degree[next]--;
            ret[next] = max(ret[next], next_cost);

            if (degree[next] == 0) {
                q.push({next, ret[next]});
            }
        }
    }
    for (int i = 1; i <= N; i++) {
        cout << ret[i] << "\n";
    }

    return 0;
}