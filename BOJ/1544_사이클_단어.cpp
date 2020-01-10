/**
 * 백준 1544번 - 사이클 단어
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 50;
int n;
vector<string> v;
string matrix[MAX];
set<pair<int, int>> s;
int visited[MAX];

int uf(int idx) {
    if (visited[idx] == idx) return idx;
    return visited[idx] = uf(visited[idx]);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        visited[i] = i;
    }
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
        matrix[i] = str + str;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (matrix[j].find(v[i]) != string::npos && matrix[i].find(v[j]) != string::npos && v[i].size() == v[j].size()) {
                int parent = uf(i);
                int child = uf(j);
                if (parent == child) continue;
                visited[child] = parent;
            }
        }
    }
    int ret = 1;
    sort(visited, visited + n);
    for (int i = 0; i < n - 1; i++) {
        if (visited[i] != visited[i + 1])
            ret++;
    }
    cout << ret << "\n";
    return 0;
}