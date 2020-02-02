/**
 * 백준 11376번 - 열혈강호 2
 * 
 * TODO:
 * 최대 유량, 이분매칭
 * 
 * 기존의 [11375번 - 열혈강호] 문제와 다르게 최대 2개의 일을 한 명이 처리할 수 있습니다.
 * 따라서 이분매칭 알고리즘에서 visited 를 int 형으로 하여 2번을 방문할 수 있게 하면됩니다.
 * 또한 두 가지의 일을 진행할 수 있으므로, DFS() 를 두 번 진행하면 됩니다. (즉 이분매칭을 두번 진행)
 * */
#include <bits/stdc++.h>

using namespace std;

// 사람과 일의 최대 크기
const int MAX = 1001;

// i 사람이 j 일을 할 수 있는가
bool matrix[MAX][MAX];

// 사람, 일의 매칭
vector<int> p_match, w_match;

// 방문 확인
vector<int> visited;

// 사람 수, 일의 갯수
int n, m;

bool DFS(int p) {
    
    // 방문 한적이 있다면 일을 처리할 수 없다는 의미이므로 false 반환
    if (visited[p] > 1)
        return false;

    visited[p]++;

    // 0 번째 일부터 처리할 수 있는지 확인
    for (int j = 0; j < m; j++) {
        if (matrix[p][j]) {
            
            // j 번째 일이 매칭되어 있지 않거나
            // j 번째 매칭되어있던 사람이 다른 일을 할 수 있을면
            // 매칭한다.
            if (w_match[j] == -1 || DFS(w_match[j])) {

                // 사람과 일을 서로 매칭
                p_match[p] = j;
                w_match[j] = p;

                // 매칭할 수 있으므로 true 반환
                return true;
            }
        }
    }

    // 아무것도 할 수 없으므로 false 반환
    return false;
}

int bipartite_matching() {
    
    // 초기화 (-1은 매치되지 않음을 뜻함)
    p_match = vector<int>(n, -1);
    w_match = vector<int>(m, -1);

    // 처리할 수 있는 일의 양
    int ret = 0;

    // 0 번째 사람부터 차례 대로 매칭
    for (int i = 0; i < n; i++) {
        
        // 방문 초기화
        visited = vector<int>(n, 0);

        // i 번째 사람 확인
        if (DFS(i)) 
            ret++;    

        if (DFS(i)) 
            ret++;     
    }
    return ret;
}

int main() {
    
    // 입력 속도 상승
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int cnt;
        cin >> cnt;
        for (int j = 0; j < cnt; j++) {
            int val;
            cin >> val;
            val--;
            matrix[i][val] = true;
        }
    }

    cout << bipartite_matching() << "\n";

    return 0;
}