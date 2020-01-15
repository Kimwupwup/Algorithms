/**
 * 백준 1092번 - 배
 * 
 * TODO: 
 * 그리디
 * */

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

map<int, int> matrix;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n, m;
    vector<int> v, w;
    vector<vector<int>> s;
    cin >> n;
    v.resize(n);
    s.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    cin >> m;
    w.resize(m);
    for (int i = 0; i < m; i++) {
        cin >> w[i];
        matrix[w[i]]++;
    }

    sort(v.begin(), v.end(), greater<int>());
    sort(w.begin(), w.end(), greater<int>());
    if (v[0] < w[0]) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (v[j] >= w[i]) {
                s[j].push_back(w[i]);
            }
        }
    }

    int ret = 0;
    int cnt = 0;
    while (true) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < s[i].size(); j++) {
                if (matrix[s[i][j]]) {
                    matrix[s[i][j]]--;
                    cnt++;
                    break;
                }
            }
        }
        
        ret++;
        if (cnt == m) {
            break;
        }
    }
    cout << ret << "\n";
    return 0;
}