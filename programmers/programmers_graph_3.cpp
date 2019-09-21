#include <string>
#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;

vector<bool> visited;
bool DFS(int node, int prev, vector<vector<int>> v) {
    for (int i = 0; i < v[node].size(); i++) {
        int next = v[node][i];
        if (visited[next] && prev != next) {
            return false;
        }
        if (!visited[next]) {
            visited[next] = true;
            bool b = DFS(next, node, v);
            visited[next] = false;
            if (b == false) return false;
        }
    }
    return true;
}

int solution(int n, vector<vector<int>> edges) {
    int answer = 0;
    vector<vector<int>> v;
    vector<int> ret;
    visited.resize(n + 1);

    for (int i = 1; i <= n; i++) {

        v.clear();
        v.resize(n + 1);

        for (int j = 0; j < edges.size(); j++) {
            int y = edges[j][0];
            int x = edges[j][1];

            if (y == i || x == i) continue;

            v[y].push_back(x);
            v[x].push_back(y);
        }

        
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            visited[i] = true;
            bool b = DFS(j, 0, v);
            visited[i] = false;
            if (b == true) {
                ret.push_back(i);
                break;
            }
        }
    }
    for (int i = 0; i < ret.size(); i++) {
        answer += ret[i];
    }
    return answer;
}

int main() {
    vector<vector<int>> edges1 = {{1,2},{1,3},{2,3},{2,4},{3,4}};
    vector<vector<int>> edges2 = {{1,2},{2,3},{3,4},{4,5},{5,6},{6,7},{7,8},{8,1},{2,7},{3,6}};

    cout << solution(4, edges1);
    cout << endl;
    cout << solution(8, edges2);
}