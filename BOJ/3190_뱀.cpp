/**
 * 백준 3190번 - 뱀
 * 
 * TODO:
 * deque
 * */

#include <iostream>
#include <deque>
#include <vector>

using namespace std;

const int MAX = 101;

vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int matrix[MAX][MAX];
vector<pair<int, char>> v;
int n, k, l;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int y, x;
        cin >> y >> x;
        matrix[y][x] = 1;
    }
    
    cin >> l;
    for (int i = 0; i < l; i++) {
        int a;
        char b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }

    deque<pair<int, int>> dq;
    dq.push_front(make_pair(1, 1));
    int ret = 0;
    int idx = 0;
    int dir_idx = 0;
    while (true) {

        if (v[dir_idx].first == ret) {
            if (v[dir_idx].second == 'D') {
                dir_idx++;
                idx = (idx + 1) % 4;
            } else {
                dir_idx++;
                idx -= 1;
                if (idx < 0)
                    idx = 3;
            }
        }
        int next_y = dq.front().first + dir[idx].first;
        int next_x = dq.front().second + dir[idx].second;
        
        if (next_y <= 0 || next_y > n || next_x <= 0 || next_x > n || matrix[next_y][next_x] == 2) {
            ret++;
            break;
        }
        else if (matrix[next_y][next_x] == 1) {
            dq.push_front(make_pair(next_y, next_x));
            matrix[next_y][next_x] = 2;
        }
        else {
            dq.push_front(make_pair(next_y, next_x));
            matrix[next_y][next_x] = 2;

            int y = dq.back().first;
            int x = dq.back().second;
            dq.pop_back();
            matrix[y][x] = 0;
        }
        ret++;
    }

    cout << ret << "\n";

    return 0;
}