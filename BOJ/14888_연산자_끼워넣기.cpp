/**
 * 백준 14888번 - 연산자 끼워넣기
 * 
 * TODO:
 * DFS
 * */

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v;
int cal[4];
int maxi = -2000000000;
int mini = 2000000000;

void solve(int idx_v, int ret) {
    if (idx_v == n) {
        if (maxi < ret) maxi = ret;
        if (mini > ret) mini = ret;
        return;
    }

    for (int i = 0; i < 4; i++) {
        if (cal[i]) {
            cal[i]--;
            switch (i) {
                case 0: solve(idx_v + 1, ret + v[idx_v]); break;
                case 1: solve(idx_v + 1, ret - v[idx_v]); break;
                case 2: solve(idx_v + 1, ret * v[idx_v]); break;
                case 3: solve(idx_v + 1, ret / v[idx_v]); break;
            }
            cal[i]++;
        }
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = 0; i < 4; i++)
        cin >> cal[i];
    
    solve(1, v[0]);
    cout << maxi << "\n";
    cout << mini << "\n";
    return 0;
}