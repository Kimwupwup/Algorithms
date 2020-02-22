/**
 * 백준 17142번 - 연구소 3
 * 
 * TODO:
 * BFS, (DFS or next_permutation)
 * 
 * 모든 경우에 대해서 next_permutation 으로 조합을 찾고
 * BFS 로 탐색을 진행합니다.
 * 다만 BFS 를 진행하면서 0 의 갯수를 다 소모했을 경우에 끝내야 하므로 0 의 갯수를
 * 알고 시작해야 합니다.
 * 그냥 BFS 를 진행하게 될 경우, 원래 구하려는 값보다 큰 값을 출력하게 됩니다.
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;
const int INF = 987654321;

vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m;
int ret;
bool good;
int matrix[MAX][MAX];
int copy_matrix[MAX][MAX];
vector<pair<int, int>> virus;
vector<int> temp;

void BFS(int cnt) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            copy_matrix[i][j] = matrix[i][j];

    queue<pair<int, int>> q;
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == 1) {
            q.push(virus[i]);
            copy_matrix[virus[i].first][virus[i].second] = 3;
        }
    }

    int time = 0;
    while (!q.empty()) {
        int size = q.size();

        if (cnt == 0) {
            good = true;
            ret = min(ret, time);
            break;
        }

        time++;

        for (int i = 0; i < size; i++) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int j = 0; j < 4; j++) {
                int next_y = y + dir[j].first;
                int next_x = x + dir[j].second;

                if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= n)
                    continue;
                
                if (copy_matrix[next_y][next_x] == 0 || copy_matrix[next_y][next_x] == 2) {
                    if (copy_matrix[next_y][next_x] == 0)
                        cnt--;
                    q.push({next_y, next_x});
                    copy_matrix[next_y][next_x] = 3;
                }
            }
        }
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 2) {
                virus.push_back({i, j});
            }
            else if (matrix[i][j] == 0) {
                cnt++;
            }
        }
    }

    ret = INF;
    temp.resize(virus.size(), 0);
    for (int i = virus.size() - m; i < virus.size(); i++)
        temp[i] = 1;
    
    do {
        BFS(cnt);
    } while (next_permutation(temp.begin(), temp.end()));

    if (good == false) {
        cout << -1 << "\n";
    }
    else {
        cout << ret << "\n";
    }
    return 0;
}