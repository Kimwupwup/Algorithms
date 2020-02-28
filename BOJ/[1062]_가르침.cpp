/**
 * 백준 1062번 - 가르침
 * 
 * */
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

const int MAX = 50;
string matrix[MAX];
bool visited[26];
int n, k, ret;

void DFS(int alpha, int cnt) {
    if (cnt == k) {
        int temp = 0;
        
        for (int i = 0; i < n; i++) {
            bool good = true;
            for (int j = 0; j < matrix[i].size(); j++) {
                if (!visited[matrix[i][j] - 'a']) {
                    good = false;
                    break;
                }
            }
            if (good)
                temp++;
        }
        ret = max(ret, temp);
        return;
    }

    for (int i = alpha; i < 26; i++) {
        if (!visited[i]) {
            visited[i] = true;
            DFS(i, cnt + 1);
            visited[i] = false;
        }
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k;

    if (k < 5) {
        cout << 0 << "\n";
        return 0;
    } else if (k == 26) {
        cout << n << "\n";
        return 0;
    }

    k -= 5;

    for (int i = 0; i < n; i++) {
        cin >> matrix[i];
        matrix[i] = matrix[i].substr(4, matrix[i].size());
        for (int j = 0; j < 4; j++)
            matrix[i].pop_back();
    }
    visited['a' - 'a'] = true;
    visited['n' - 'a'] = true;
    visited['t' - 'a'] = true;
    visited['i' - 'a'] = true;
    visited['c' - 'a'] = true;

    DFS(0, 0);
    cout << ret << "\n";
    return 0;
}