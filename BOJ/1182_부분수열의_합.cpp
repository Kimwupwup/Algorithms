/**
 * 백준 1182번 - 부분수열의 합
 * 
 * TODO:
 * 완전 탐색, DFS
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 20;

vector<int> matrix;
int n, m;
int ret = 0;

void DFS(int idx, int sum, int cnt) {
    if (sum == m && cnt > 0) {
        ret++;
    }

    for (int i = idx; i < n; i++) {
        DFS(i + 1, sum + matrix[i], cnt + 1);
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        matrix.push_back(temp);
    }

    DFS(0, 0, 0);
    cout << ret << "\n";

    return 0;
}