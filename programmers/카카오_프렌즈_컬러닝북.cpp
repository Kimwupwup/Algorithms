#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    vector<int> answer(2);
    answer[0] = 0;
    answer[1] = 0;

    vector<int> color_cnt;
    vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(m);
    for (int i = 0; i < m; i++) {
        visited[i].resize(n, false);
    }

    int current_color;
    int cnt;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && picture[i][j] != 0) {
                q.push({i, j});
                visited[i][j] = true;
                cnt = 1;
                answer[0]++;
                current_color = picture[i][j];

                while (!q.empty()) {
                    int y = q.front().first;
                    int x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int next_y = y + dir[k].first;
                        int next_x = x + dir[k].second;

                        if (next_y >= 0 && next_y < m && next_x >= 0 && next_x < n) {
                            if (!visited[next_y][next_x] && picture[next_y][next_x] == current_color) {
                                q.push({next_y, next_x});
                                visited[next_y][next_x] = true;
                                cnt++;
                            }
                        }
                    }
                }
                color_cnt.push_back(cnt);
            }
        }
    }
    sort(color_cnt.begin(), color_cnt.end(), greater<int>());
    answer[1] = color_cnt[0];
    return answer;
}

// #include <vector>
// #include <queue>
// #include <algorithm>

// using namespace std;

// // 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
// vector<int> solution(int m, int n, vector<vector<int>> picture) {
//     vector<int> answer(2);
//     answer[0] = 0;
//     answer[1] = 0;

//     vector<vector<int>> visit(m);
//     for (int i = 0; i < m; i++) {
//         visit[i].resize(n, 0);
//     }

//     queue<pair<int, int>> q;
//     vector<pair<int, int>> dx = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//     vector<int> width;
//     int cnt = 0;
//     int area = 0;
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (picture[i][j] && !visit[i][j])
//             {
//                 cnt++;
//                 q.push({i, j});
//                 visit[i][j] = cnt;
//                 while (!q.empty())
//                 {
//                     area++;
//                     int x = q.front().first;
//                     int y = q.front().second;
//                     q.pop();
//                     for (int k = 0; k < 4; k++)
//                     {
//                         int nx = dx[k].first + x;
//                         int ny = dx[k].second + y;
//                         if (nx >= 0 && nx < m && ny >= 0 && ny < n)
//                         {
//                             if (picture[x][y] == picture[nx][ny] && !visit[nx][ny])
//                             {
//                                 q.push({nx, ny});
//                                 visit[nx][ny] = cnt;
//                             }
//                         }
//                     }
//                 }
//                 width.push_back(area);
//                 area = 0;
//             }
//         }
//     }
    
//     sort(width.begin(), width.end(), greater<int>());
//     answer[0] = cnt;
//     answer[1] = width[0];
//     return answer;
// }