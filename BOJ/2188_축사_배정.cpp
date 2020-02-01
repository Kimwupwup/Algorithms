/**
 * 백준 2188번 - 축사배정
 * 
 * TODO:
 * 이분 매칭
 * https://www.crocus.co.kr/499
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 201;
const int MAX_M = 201;

bool matrix[MAX_N][MAX_M];

vector<int> a_match, b_match;

vector<bool> visited;
int n, m;

bool DFS(int a) {
    if (visited[a]) 
        return false;
    
    visited[a] = true;

    for (int b = 0; b < m; b++) {
        if (matrix[a][b]) {
            if (b_match[b] == -1 || DFS(b_match[b])) {
                a_match[a] = b;
                b_match[b] = a;

                return true;
            }
        }
    }
    return false;
}

int bipartiteMatch() {
    a_match = vector<int>(n, -1);
    b_match = vector<int>(m, -1);

    int size = 0;

    for (int start = 0; start < n; start++) {
        visited = vector<bool>(n, false);
        if (DFS(start)) {
            size++;
        }
    }

    return size;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int value;
            cin >> value;
            value--;
            matrix[i][value] = true;
        }
    }
    cout << bipartiteMatch() << "\n";
    return 0;
}