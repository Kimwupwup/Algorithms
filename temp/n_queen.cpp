/**
 * 백준 9663번 - N-Queen
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 15;
int n;
int matrix[MAX];

bool chk(int idx) {
    for (int i = 0; i < idx; i++) {
        if (matrix[i] == matrix[idx] || abs(matrix[i] - matrix[idx]) == abs(i - idx))
            return false;
    }
    return true;
}

int solve(int idx) {
    int ret = 0;

    if (idx == n) return 1;
    for (int i = 0; i < n; i++) {
        matrix[idx] = i;
        if (chk(idx))
            ret += solve(idx + 1);
    }

    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;

    int ret = 0;
    for (int i = 0; i < n / 2; i++) {
        matrix[0] = i;
        ret += solve(1);
    }

    ret *= 2;
    if (n % 2 == 1) {
        matrix[0] = n / 2;
        ret += solve(1);
    }

    cout << ret << "\n";
    return 0;
}