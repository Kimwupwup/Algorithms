#include <string>
#include <vector>
#include <queue>

using namespace std;

const vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

pair<pair<int, int>, int> first_turn(pair<pair<int, int>, int> drone, vector<vector<int>> board, bool clock) {
    int type = clock ? 1 : -1;
    int second = drone.second;
    int y = drone.first.first;
    int x = drone.first.second;

    if (type == 1) {
        if (board[y + dir[second].first][x + dir[second].second])
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    vector<vector<bool>> visited;
    vector<bool> temp;
    temp.resize(board.size(), false);
    visited.resize(board.size(), temp);

    pair<pair<int, int>, int> drone;
    
    queue<pair<pair<int, int>, int>> q;
    q.push(drone);
    visited[0][0] = true;
    visited[0][1] = true;

    while (!q.empty()) {
        int size = q.size();
        for (int j = 0; j < size; j++) {
            int y = q.front().first.first;
            int x = q.front().first.second;
            q.pop();

            if (y == board.size() - 1 && x == board.size() - 1) {
                return answer;
            }
            for (int i = 0; i < 4; i++) {
                int next_y = y + dir[i].first;
                int next_x = x + dir[i].second;

                if (next_y < 0 || next_y >= board.size() || next_x < 0 || next_y >= board.size() || visited[next_y][next_x] || board[next_y][next_x] == 1) 
                    continue;
                
                visited[next_y][next_x] = true;
                q.push();
            }
        }
    }

    return answer;
}
