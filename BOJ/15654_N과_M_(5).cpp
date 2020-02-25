/**
 * 백준 15654번 - N과 M (5)
 * 
 * TODO:
 * DFS, 비트마스크
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 8;
vector<int> matrix;
int n, m;

void DFS(int mask, vector<int> temp) {
    if (temp.size() == m) {
        for (int a : temp)
            cout << a << " ";
        cout << "\n";
        return;
    }

    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;
        temp.push_back(matrix[i]);
        DFS(mask | (1 << i), temp);
        temp.pop_back();
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    matrix.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    sort(matrix.begin(), matrix.end());
    DFS(0, {});
    return 0;
}