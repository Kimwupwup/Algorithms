/**
 * 백준 4485번 - 녹색 옷 입은 애가 젤다지?
 * 
 * TODO:
 * 다익스트라
 * */
#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
const int MAX = 125;
const int INF = 987654321;
int matrix[MAX][MAX];
int cache[MAX][MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int idx = 1;
    while (true) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
                cache[i][j] = INF;
            }
                
        
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        cache[0][0] = matrix[0][0];
        pq.push({cache[0][0], {0, 0}});

        while (!pq.empty()) {
            int y = pq.top().second.first;
            int x = pq.top().second.second;
            int cost = pq.top().first;
            pq.pop();

            for (int i = 0; i < 4; i++) {
                int next_y = y + dir[i].first;
                int next_x = x + dir[i].second;
                int next_cost = cost + matrix[next_y][next_x];

                if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n || next_cost >= cache[next_y][next_x]) 
                    continue;
                
                cache[next_y][next_x] = next_cost;
                pq.push({next_cost, {next_y, next_x}});                
            }
        }
        cout << "Problem " << idx << ": " << cache[n - 1][n - 1] << "\n";
        idx++;
    }

    return 0;
}