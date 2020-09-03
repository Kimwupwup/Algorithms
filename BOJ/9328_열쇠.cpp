#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 102;
const vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

int n, m;
char matrix[MAX][MAX];
bool visited[MAX][MAX];
bool keys[26];
int ret;
void BFS(int y, int x);

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    
    while (t--) {
        memset(keys, false, sizeof(keys));
        memset(visited, false, sizeof(visited));
        for (int i = 0; i < MAX; i++) {
            for (int j = 0; j < MAX; j++) {
                matrix[i][j] = '.';
            }
        }

        cin >> n >> m;
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> matrix[i][j];
            }
        }

        string temp;
        cin >> temp;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == '0') break;
            keys[temp[i] - 'a'] = true;
            for (int y = 1; y <= n; y++)
                for (int x = 1; x <= m; x++) 
                    if (matrix[y][x] - 'A' == temp[i] - 'a')
                        matrix[y][x] = '.';
        }

        ret = 0;
        BFS(0, 0);
        cout << ret << "\n";
    }

    return 0;
}

void BFS(int y, int x) {
    queue<pair<int, int>> q;

    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int next_y = cur_y + dir[i].first;
            int next_x = cur_x + dir[i].second;

            // 예외 처리
            if (next_y < 0 || next_y > n + 1 || next_x < 0 || next_x > m + 1)
                continue;
            if (visited[next_y][next_x] || matrix[next_y][next_x] == '*' || (matrix[next_y][next_x] >= 'A' && matrix[next_y][next_x] <= 'Z'))
                continue;
            
            // 문서를 찾음
            if (matrix[next_y][next_x] == '$') {
                ret++;
                matrix[next_y][next_x] = '.';
                visited[next_y][next_x] = true;
                q.push({next_y, next_x});
            }
            
            // 열쇠를 찾음
            else if (matrix[next_y][next_x] >= 'a' && matrix[next_y][next_x] <= 'z') {                            

                // 열쇠에 맞는 문을 열어둔다.
                if (!keys[matrix[next_y][next_x] - 'a']) {
                    keys[matrix[next_y][next_x] - 'a'] = true;

                    for (int a = 1; a <= n; a++) 
                        for (int b = 1; b <= m; b++) 
                            if (matrix[a][b] - 'A' == matrix[next_y][next_x] - 'a')
                                matrix[a][b] = '.';
                                
                    memset(visited, false, sizeof(visited));
                }
                matrix[next_y][next_x] = '.';   
                visited[next_y][next_x] = true;
                q.push({next_y, next_x});
            }
            else if (matrix[next_y][next_x] == '.') {
                visited[next_y][next_x] = true;
                q.push({next_y, next_x});
            }
        }
    }
}