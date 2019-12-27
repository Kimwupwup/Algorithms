/** 
 * 백준 14499번 - 주사위 굴리기
 * 
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 20;
int matrix[MAX][MAX];
int n, m, y, x, k;
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
vector<int> v;
struct Dice {
    int bottom = 0;
    int west = 0;
    int east = 0;
    int north = 0;
    int south = 0;
    int top = 0;
};

Dice dice;

void move(int idx) {
    int _bottom = dice.bottom;
    int _west = dice.west;
    int _east = dice.east;
    int _north = dice.north;
    int _south = dice.south;
    int _top = dice.top;
    if (idx == 1) {
        dice.bottom = _east;
        dice.west = _bottom;
        dice.east = _top;
        dice.north = _north;
        dice.south = _south;
        dice.top = _west;
    } else if (idx == 2) {
        dice.bottom = _west;
        dice.west = _top;
        dice.east = _bottom;
        dice.north = _north;
        dice.south = _south;
        dice.top = _east;
    } else if (idx == 3) {
        dice.bottom = _south;
        dice.west = _west;
        dice.east = _east;
        dice.north = _bottom;
        dice.south = _top;
        dice.top = _north;
    } else if (idx == 4) {
        dice.bottom = _north;
        dice.west = _west;
        dice.east = _east;
        dice.north = _top;
        dice.south = _bottom;
        dice.top = _south;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> y >> x >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    
    for (int i = 0; i < k; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    int cur_x = x;
    int cur_y = y;
    for (int i = 0; i < k; i++) {
        int next_y = cur_y + dir[v[i] - 1].first;
        int next_x = cur_x + dir[v[i] - 1].second;

        if (next_y < 0 || next_y >= n || next_x < 0 || next_x >= m)
            continue;
        
        cur_y = next_y;
        cur_x = next_x;
        move(v[i]);
        if (matrix[cur_y][cur_x] == 0) {
            matrix[cur_y][cur_x] = dice.bottom;
        } else {
            dice.bottom = matrix[cur_y][cur_x];
            matrix[cur_y][cur_x] = 0;
        }
        cout << dice.top << "\n";
    }
    return 0;
}
