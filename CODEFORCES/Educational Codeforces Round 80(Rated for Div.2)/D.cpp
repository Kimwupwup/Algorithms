/**
 * Educational Codeforces Round 80
 * D. 
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

const int MAX = 3 * 100000;
const int WIDTHMAX = 8;
int matrix[MAX][WIDTHMAX];
int n, m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int ret = 0;
    int a, b;
    vector<int> v;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i; j < n; j++) {
            v.clear();
            for (int k = 0; k < m; k++) {
                v.push_back(max(matrix[i][k], matrix[j][k]));
            }
            int mini = INT_MAX;
            for (int k = 0; k < v.size(); k++) {
                if (mini > v[k]) {
                    mini = v[k];
                }
            }
            if (ret < mini) {
                a = i + 1;
                b = j + 1;
                ret = mini;
            }
        }
    }
    cout << a << " " << b << "\n";
    return 0;
}