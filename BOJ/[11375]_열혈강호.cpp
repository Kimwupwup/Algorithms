/**
 * 백준 11375번 - 열혈강호
 * 
 * TODO:
 * 최대 유량, 이분 매칭
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 1001;

// 사람, 일의 갯수
int n, m;

// i 사람이 j 일을 할 수 있는가?
bool matrix[MAX][MAX];

// 사람, 일에 대한 매치
vector<int> p_match, w_match;

// 방문 확인
vector<bool> visited;

/// 깊이 우선 탐색(parameter: (p: 사람))
bool DFS(int p) {
    if (visited[p])
        return false;
    
    visited[p] = true;

    for (int i = 0; i < m; i++) {

        // 해당 사람이 그 일을 할 수 있는가
        if (matrix[p][i]) {
            
            // 해당 일이 사람과 매칭되어 있지 않거나
            // 매칭되어 있다면, 매칭되어 있는 사람이 다른 일을 할 수 있다면
            // 현재 사람과 현재 일을 매칭
            if (w_match[i] == -1 || DFS(w_match[i])) {
                
                // 사람과 일을 서로 매칭
                w_match[i] = p;
                p_match[p] = i;
                return true;
            }
        }
    }
    return false;
}

int bipartiteMatch() {
    // 사람, 일 매치 정보 초기화(-1 은 아무것도 고르지 않았다는 뜻)
    p_match = vector<int>(n, -1);
    w_match = vector<int>(m, -1);

    // 처리할 수 있는 일의 갯수
    int ret = 0;

    // 첫 번째 사람부터 하나씩 처리
    for (int start = 0; start < n; start++) {

        // 방문은 매번 초기화
        visited = vector<bool>(n, false);

        // 해당 사람이 일을 처리할 수 있다면
        if (DFS(start)) 
            ret++;
    }
    return ret;
}

int main() {
    
    // 입력 속도 단축
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;

        // i 번째 사람이 할 수 있는 일 체크
        for (int j = 0; j < cnt; j++) {
            int val;
            cin >> val;
            val--;
            matrix[i][val] = true;
        }
    }

    cout << bipartiteMatch() << "\n";
    return 0;
}