/**
 * 백준 15685번 - 드래곤 커브
 * 
 * 2^i 는 무조건 LEFT
 * 방향 전환할 때마다 vector에 추가
 * 세대가 추가 될대는 vector를 거꾸로 진행하며, 방향도 거꾸로 한다.
 * */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 101;
int matrix[MAX][MAX];
vector<vector<int>> v;
vector<pair<int, int>> dir = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}}; // CCW

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        tmp = {y, x, d, g};
        v.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        int y = v[i][0];
        int x = v[i][1];
        int d = v[i][2];
        int g = v[i][3];

        vector<int> st;
        matrix[y][x] = i + 1;
        int idx = 0;
        int cur_gen = 0;
        while (pow(2, g) > idx) {
            if (pow(2, cur_gen) == idx) {                
                d = (d + 1) % 4;
                st.push_back(1);
                y += dir[d].first;
                x += dir[d].second;
                matrix[y][x] = i + 1;
                cur_gen++;
                idx++;
            } else if (st.empty()) {
                y += dir[d].first;
                x += dir[d].second;
                matrix[y][x] = i + 1;
                idx++;
            } else {
                int size = st.size();
                for (int j = 2; j <= size; j++) {
                    d = (d - st[size - j]) % 4;
                    if (d < 0)
                        d = 4 + d;
                    y += dir[d].first;
                    x += dir[d].second;
                    matrix[y][x] = i + 1;
                    if (st[size - j] == 1)
                        st.push_back(-1);
                    else
                        st.push_back(1);
                    idx++;
                }
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (matrix[i][j] && matrix[i][j + 1] && matrix[i + 1][j] && matrix[i + 1][j + 1])
                ret++;
        }
    }
    cout << ret << '\n';
    return 0;
}