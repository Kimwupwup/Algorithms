/**
 * 백준 15686번 - 치킨 배달
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 50;
const int INF = 987654321;

int n, m;
int ret = INF;
int matrix[MAX][MAX];
bool visited[13];

vector<pair<int, int>> save;
vector<pair<int, int>> chicken;
vector<pair<int, int>> house;

int distance(pair<int, int> a, pair<int, int> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void DFS(int idx, int cnt) {
    if (cnt == m) {
        int temp = 0;
        for (int i = 0; i < house.size(); i++) {
            int dist = INF;
            for (int j = 0; j < chicken.size(); j++) {
                if (visited[j])
                    dist = min(dist, distance(house[i], chicken[j]));
            }
            temp += dist;
        }
        ret = min(ret, temp);
        return;
    }

    if (idx == chicken.size())
        return;

    visited[idx] = true;
    DFS(idx + 1, cnt + 1);

    visited[idx] = false;
    DFS(idx + 1, cnt);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1) {
                house.push_back(make_pair(i, j));
            } else if (matrix[i][j] == 2) {
                chicken.push_back(make_pair(i, j));
            }
        }
    }
    ret = INF;
    DFS(0, 0);
    
    cout << ret << "\n";
    return 0;
}