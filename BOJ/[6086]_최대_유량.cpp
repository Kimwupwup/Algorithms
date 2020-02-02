/**
 * 백준 6086번 - 최대 유량
 * 
 * TODO:
 * 최대 유량
 * */
#include <bits/stdc++.h>

using namespace std;

// 알파벳 소문자, 대문자 갯수
const int MAX = 52;

const int INF = 987654321;

int n;

// 유량의 흐름을 찾기 위한 경로
int trace[MAX];

// i - j 간선의 유량
int capacity[MAX][MAX];

// 흐르는 유량
int flow[MAX][MAX];

// i 번째 간선에 연결된 노드
vector<int> vec[MAX];

// A ~ z 까지 아스키코드로 변형
int ASCII_to_int(char c) {
    if (c <= 'Z')
        return c - 'A';
    return c - 'a' + 26;
}

int main() {

    // 입력 속도 상승
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        char u, v;
        int temp_u, temp_v, w;
        cin >> u >> v >> w;

        temp_u = ASCII_to_int(u);
        temp_v = ASCII_to_int(v);

        // 유량 누적
        capacity[temp_u][temp_v] += w;
        capacity[temp_v][temp_u] += w;

        // 방향 지정
        vec[temp_u].push_back(temp_v);
        vec[temp_v].push_back(temp_u);
    }

    int start = ASCII_to_int('A');
    int finish = ASCII_to_int('Z');

    // BFS 를 통해 trace(시작 지점부터 도착 지점까지의 루트)를 찾고
    // 그 루트에서 최소 유량을 찾아 해당 루트의 flow(간선에 흐르는 유량)을 추가한다.
    // 이 때, 정방향으로 흐르는 유량은 "+"로, 역방향으로 흐르는 유량은 "-"를 더한다.
    // 현재 흐르는 유량을 업데이트한다.
    // 이를 반복하면서 BFS 에서 도착 지점까지 도달하지 못할 때까지 반복하게 되면
    // 최대 유량을 찾을 수 있다.
    int ret = 0;
    while (true) {

        // BFS 로 경로 탐색
        memset(trace, -1, sizeof(trace));
        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < vec[cur].size(); i++) {
                int next = vec[cur][i];

                // 역으로 흐르는 경우도 고려한다.
                // flow 가 음수면 항상 흐를 수 있다.
                // flow 가 용량을 넘어가면 흐를 수 없는 상태를 의미한다.
                if (trace[next] == -1 && capacity[cur][next] - flow[cur][next] > 0) {
                    q.push(next);
                    trace[next] = cur;
                }
            }
        }

        // finish 에 도달할 수 없으면 탈출
        if (trace[finish] == -1) {
            break;
        }

        // 가장 작은 유량 찾기
        int mini = INF;
        for (int i = finish; i != start; i = trace[i])
            mini = min(mini, capacity[trace[i]][i] - flow[trace[i]][i]);

        // flow 에 찾은 가장 작은 유량을 각 간선(흐름)에 추가한다.
        // 반대 방향으로는 음수로 추가한다.
        for (int i = finish; i != start; i = trace[i]) {
            flow[trace[i]][i] += mini;
            flow[i][trace[i]] -= mini;
        }
        ret += mini;
    }

    cout << ret << "\n";

    return 0;
}