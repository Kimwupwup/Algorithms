/**
 * 백준 2309번 - 일곱 난쟁이
 * 
 * TODO:
 * 완전탐색, DFS, 비트마스크
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 9;
int matrix[MAX];
vector<int> ret;

void DFS(int cnt, int sum, int visited) {
    if (cnt == 7) {
        if (sum != 100) return;
        sort(ret.begin(), ret.end());
        for (int a : ret)
            cout << a << "\n";
        exit(0);
    }

    for (int i = 0; i < MAX; i++) {
        if (visited & (1 << i)) continue;
        ret.push_back(matrix[i]);
        DFS(cnt + 1, sum + matrix[i], visited | (1 << i));
        ret.pop_back();
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    for (int i = 0; i < MAX; i++) {
        cin >> matrix[i];
    }

    DFS(0, 0, 0);

    return 0;
}