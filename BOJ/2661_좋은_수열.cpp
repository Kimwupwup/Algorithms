/**
 * 백준 2661번 - 좋은 수열
 * 
 * TODO:
 * 백트랙킹
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 80;
int matrix[MAX];
int n;

bool chk(int idx) {
    for (int i = 0; i <= idx / 2; i++) {
        int cnt = i + 1;
        for (int j = idx; j >= idx - i; j--) {
            if (matrix[j] == matrix[j - i - 1])
                cnt--;
        }
        if (cnt == 0)
            return false;
    }
    return true;
}

void solve(int idx) {
    if (idx == n) {
        for (int i = 0; i < n; i++) {
            cout << matrix[i];
        }
        exit(0);
    }

    for (int i = 1; i <= 3; i++) {
        matrix[idx] = i;
        if (chk(idx))
            solve(idx + 1);
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    solve(0);
    return 0;
}