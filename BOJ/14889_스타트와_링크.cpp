/**
 * 백준 14889번 - 스타트와 링크
 * 
 * 완전탐색 DFS
 * */

#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < (int)n; i++)
using namespace std;

const int MAX = 20;
int matrix[MAX][MAX];
int n;
int ret = 2000000000;
bool visited[MAX];

void solve(int idx, int cnt, vector<int> startlink) {
    if (cnt == n / 2) {
        int team_start = 0;
        int team_link = 0;
        for (int i = 0; i < (n / 2) - 1; i++) {
            for (int j = i + 1; j < (n / 2); j++) {
                team_start += matrix[startlink[i]][startlink[j]];
                team_start += matrix[startlink[j]][startlink[i]];
            }
        }
        vector<int> linkstart;
        forn (i, n) {
            if (!visited[i])
                linkstart.push_back(i);
        }
        for (int i = 0; i < (n / 2) - 1; i++) {
            for (int j = i + 1; j < (n / 2); j++) {
                team_link += matrix[linkstart[i]][linkstart[j]];
                team_link += matrix[linkstart[j]][linkstart[i]];
            }
        }
        if (ret > abs(team_start - team_link)) {
            ret = abs(team_start - team_link);
        }
        return;
    }

    for (int i = idx; i < n; i++) {
        visited[i] = true;
        startlink.push_back(i);
        solve(i + 1, cnt + 1, startlink);
        visited[i] = false;
        startlink.pop_back();
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    forn (i, n) 
        forn (j, n)
            cin >> matrix[i][j];
    
    solve(0, 0, {});
    cout << ret << "\n";
    return 0;
}