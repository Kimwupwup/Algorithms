/**
 * 백준 15663번 - N과 M (9)
 * 
 * TODO:
 * set (중복제거), DFS
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 8;
set<vector<int>> s;
vector<int> v;
int n, m;

void DFS(vector<int> temp, int mask) {
    if (temp.size() == m) {
        s.insert(temp);
        return;
    }

    for (int i = 0; i < n; i++) {
        if (mask & (1 << i)) continue;
        temp.push_back(v[i]);
        DFS(temp, mask | (1 << i));
        temp.pop_back();
    }
    return;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    DFS({}, 0);
    set<vector<int>>::iterator iter;
    for (iter = s.begin(); iter != s.end(); iter++) {
        vector<int> temp = *iter;
        for (int i = 0; i < temp.size(); i++) {
            cout << temp[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}