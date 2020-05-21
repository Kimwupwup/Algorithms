/**
 * 백준 2623번 - 음악프로그램
 * 
 * TODO:
 * 위상 정렬
 * */
#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

const int MAX = 1001;
int N, M;
int degree[MAX];
set<int> matrix[MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    for (int i = 0; i < M; i++) {
        int size;
        cin >> size;
        vector<int> v(size);

        for (int j = 0; j < size; j++) {
            cin >> v[j];
        }

        for (int j = 0; j < size - 1; j++) {           
            if (matrix[v[j]].count(v[j + 1]) != 0) continue;
            matrix[v[j]].insert(v[j + 1]);
            degree[v[j + 1]]++;            
        }
    }

    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= N; i++) {
        if (degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ret;
    while (!q.empty()) {
        int cur = q.top();
        q.pop();

        ret.push_back(cur);

        for (set<int>::iterator iter = matrix[cur].begin(); iter != matrix[cur].end(); iter++) {
            int next = *iter;
            
            degree[next]--;

            if (degree[next] == 0) {
                q.push(next);
            }
        }
    }

    if (ret.size() != N)
        cout << 0 << "\n";
    else 
        for (int a : ret)
            cout << a << "\n";
    return 0;
}