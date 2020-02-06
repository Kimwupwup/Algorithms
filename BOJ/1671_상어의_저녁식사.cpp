/**
 * 백준 1671번 - 상어의 저녁식사
 * 
 * TODO:
 * 이분 매칭
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 50;

struct node {
    int a;
    int b;
    int c;
};

int n;

node jaws[MAX];
bool matrix[MAX][MAX];
int visited[MAX];
int a_match[MAX];
int b_match[MAX];

bool DFS(int a) {
    if (visited[a] == 1) return false;

    visited[a] = 1;

    for (int b = 0; b < n; b++) {
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

int bipartite_matching() {
    int ret = 0;
    
    memset(a_match, -1, sizeof(a_match));
    memset(b_match, -1, sizeof(b_match));

    for (int a = 0; a < n; a++) {
        memset(visited, 0, sizeof(visited));
        ret += DFS(a);

        memset(visited, 0, sizeof(visited));
        ret += DFS(a);
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        jaws[i].a = a;
        jaws[i].b = b;
        jaws[i].c = c;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (jaws[i].a == jaws[j].a && jaws[i].b == jaws[j].b && jaws[i].c == jaws[j].c && i > j) continue;
            if (jaws[i].a >= jaws[j].a && jaws[i].b >= jaws[j].b && jaws[i].c >= jaws[j].c) matrix[i][j] = true;
        }
    }

    int temp = bipartite_matching();
    cout << n - temp << "\n";
    return 0;
}