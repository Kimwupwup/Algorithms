/**
 * 백준 5214번 - 환승
 * 
 * TODO:
 * 플로이드 와샬(메모리 초과)
 * BFS(더미 필요)
 * 
 * 모든 역을 연결할게 되면 메모리 초과가 발생한다.
 * 각 튜브가 1000개의 역과 연결되어 있다고 한다면, (1000개의 튜브) * (1000개의 역 * 1000개의 역) 으로 메모리 초과가 발생한다.
 * 
 * 이를 막기 위해서 더미 역을 만들 필요가 있다.
 * 0 ~ 100001 까지는 역 번호이며, 이는 해당 역에 오는 튜브의 번호가 있다.
 * 100001 ~ 110001 까지는 튜브의 번호이며, 이는 해당 튜브가 갈 수 있는 역의 번호가 있다.
 * 위 두개를 따로 분리하여 처리할 수 있다.
 * 이러한 구조를 사용하게 되면, 1000개의 튜브가 1000개의 역을 간다하더라도 (1000개의 튜브) * (1000개의 역 + 1000개의 튜브) 만 저장되기 때문에
 * 메모리 초과가 발생하지 않는다.
 * 
 * BFS을(를) 수행할 때,
 * 1. 1번 역부터 큐에 넣고 시작한다.(ret 는 지나친 역의 개수를 뜻하면 1 번을 거치므로 1 로 시작한다.)
 * 
 * 2. matrix[1] 에는 1 번 역(cur <= 100001)에 오는 튜브의 번호(next > 100001)가 들어가 있으며, 이 번호들을 큐에 넣는다.
 * 2-2. ex) matrix[100003] 은 2번 튜브(cur > 100001)가 가는 역의 번호(next <= 100001)가 들어가 있으며, 이 번호를 큐에 넣는다.
 * 
 * 3. next 가 100001 보다 클 경우, 역이 아닌 튜브를 뜻하므로 cost 는 바뀌지 않는다.(cost[next] = cost[cur])
 * 3-2. next 가 100001 보자 작을 경우, 역을 뜻(역을 지나간다.)하므로 cost 는 1 추가 된다.(cost[next] = cost[cur] + 1)
 * 
 * 현재 번호가 100001 을 기준으로 작을 경우는 큐에 튜브 번호가 추가([2] 실행), 클 경우에는 역 번호가 추가([2-2] 실행)
 * 현재 번호가 100001 을 기준으로 작을 경우는 cost 를 유지하지만([3] 실행), 클 경우에는 cost 가 늘어난다.([3-2] 실행)
 * 
 * 위의 실행 과정을 한번씩 번갈아가며 실행하게 된다. 
 * (역 1 추가 -> 역 1 로 오는 튜브 전부 추가 -> 각 튜브가 가는 역 전부 추가 -> 각 역에 오는 튜브 전부 추가 -> ....)
 * 보통 BFS 로 실행하는 경우의 2배 가량의 시간이 소모된다고 생각하면 된다.(역에서 역으로 가는 간선만 고려하지만 이 문제는 역에서 튜브, 튜브에서 역으로 가는 간선)
 * 
 * 무한루프는 cost가 0이 아닐 때만 처리하도록 하면, 방지할 수 있다.
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100001;
const int INF = 987654321;

vector<int> matrix[MAX + 1000];
int cost[MAX + 1000];
int n, k, m;

int solve() {
    queue<int> q;
    cost[1] = 1;
    q.push(1);

    while (!q.empty()) {
        int cur = q.front();
        q.pop();

        if (cur == n) 
            return cost[cur];
        
        for (int i = 0; i < matrix[cur].size(); i++) {
            int next = matrix[cur][i];

            if (cost[next] != 0) continue;
            
            q.push(next);
            if (next > MAX)
                cost[next] = cost[cur];
            else
                cost[next] = cost[cur] + 1;
        }
    }
    return -1;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> k >> m;

    for (int i = 1; i <= m; i++) {        
        for (int j = 0; j < k; j++) {
            int temp;
            cin >> temp;
            matrix[temp].push_back(MAX + i);
            matrix[MAX + i].push_back(temp);
        }
    }
    cout << solve() << "\n";
    return 0;
}