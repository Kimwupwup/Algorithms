/**
 * 백준 3184번 - 양
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 250;
const vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
int n, m;
char matrix[MAX][MAX];
bool visited[MAX][MAX];
int sheep = 0;
int wolf = 0;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 'o')
                sheep++;
            else if (matrix[i][j] == 'v')
                wolf++;
        }
    }

    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != '#' && !visited[i][j]) {
                visited[i][j] = true;
                q.push(make_pair(i, j));
                int temp_sheep = 0;
                int temp_wolf = 0;
                
                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    if (matrix[y][x] == 'v')
                        temp_wolf++;
                    else if (matrix[y][x] == 'o')
                        temp_sheep++;
                    
                    for (int k = 0; k < 4; k++) {
                        int next_y = y + dir[k].first;
                        int next_x = x + dir[k].second;

                        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m || visited[next_y][next_x] || matrix[next_y][next_x] == '#')
                            continue;
                        
                        visited[next_y][next_x] = true;
                        q.push(make_pair(next_y, next_x));
                    }
                }
                if (temp_sheep > temp_wolf)
                    wolf -= temp_wolf;
                else 
                    sheep -= temp_sheep;
            }
        }
    }

    cout << sheep << " " << wolf << "\n";
    return 0;
}