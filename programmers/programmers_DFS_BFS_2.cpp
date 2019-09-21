#include <string>
#include <vector>
#include <iostream>
#include <memory.h>
#include <queue>

using namespace std;

bool visited[200][200];

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    queue<pair<int, int>> q;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && computers[i][j] == 1) {
                answer++;
                q.push({i, j});
                visited[i][j] = true;

                while (!q.empty()) {
                    //cout << q.size() << endl;
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k < n; k++) {
                        if (!visited[x][k] && computers[x][k] == 1) {
                            q.push({x, k});
                            visited[x][k] = true;
                        }
                    }
                }
            }

        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << visited[i][j] << " ";
        }
        cout << endl;
    }
    return answer;
}

int main() {
    vector<vector<int>> computers = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    vector<vector<int>> computers2 = {
        {1, 1, 0},
        {1, 1, 1},
        {0, 1, 1}
    };

    cout << solution(3, computers) << endl;
    cout << solution(3, computers2) << endl;
}