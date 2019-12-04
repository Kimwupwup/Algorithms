/**
 * 백준 2618번 - 경찰차
 * 
 * FIXME:
 * DP, 백트렉킹
 * 거꾸로 다가가야한다.
 * dp[i][j] 는 경찰차1이 i 번째, 경찰차2가 j 번째 일을 수행하였을 때,
 * 남은 최소 거리를 저장한다.
 * 
 * */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;
const int MAX = 1001;

int dp[MAX][MAX];
int N, W;

pair<int, int> pol1[MAX];
pair<int, int> pol2[MAX];

vector<int> tracking;

// pos1 은 경찰차1이 수행한 목적지 index
// pos2 는 경찰차2가 수행한 목적지 index
int solution (int pos1, int pos2) {
    
    // 둘다 모든 일을 마쳤을 때에는 남은 최소 이동거리가 0 이므로 0 반환
    if (pos1 == W ||  pos2 == W)
        return 0;

    // pos1, pos2 의 저장값을 확인하고 수행한적 있다면 바로 반환
    int &ret = dp[pos1][pos2];
    if (ret != -1)
        return ret;
    
    // 다음 목적지의 index
    int next_pos = max (pos1, pos2) + 1;

    // 다음 목적지와 현재 경찰차1과의 거리 계산
    int distOfPol1 = 
        abs (pol1[next_pos].first - pol1[pos1].first) + abs (pol1[next_pos].second - pol1[pos1].second);

    // 다음 목적지에 대해서 수행(경찰차1)
    // solution (next_pos, pos2) : 현재 경찰차를 다음 목적지에 수행하였을 때, 남은 최소 이동 거리
    // distOfPol1 : 현재 경찰차와 다음 목적지까지의 거리
    // next_pol1 : 현재 경찰차가 최종 목적지까지 남은 최소 이동 거리
    int next_pol1 = solution (next_pos, pos2) + distOfPol1;

    // 다음 목적지와 현재 경찰차2와의 거리 계산
    int distOfPol2 = 
        abs (pol2[next_pos].first - pol2[pos2].first) + abs (pol2[next_pos].second - pol2[pos2].second);

    // 다음 목적지에 대해서 수행(경찰차2)
    int next_pol2 = solution (pos1, next_pos) + distOfPol2;

    // 위 두 경찰차에 대해서 모두 수행하고
    // 최솟값이 되는 값을 dp에 저장
    // 즉, 두 경찰차 중에 남은 최소 이동 거리가 작은 것이 저장됨.
    return ret = min (next_pol1, next_pol2);
}

void trace (int pos1, int pos2) {
    if (pos1 == W || pos2 == W)
        return;

    int next_pos = max (pos1, pos2) + 1;
    int distOfPol1 = 
        abs (pol1[next_pos].first - pol1[pos1].first) + abs (pol1[next_pos].second - pol1[pos1].second);
    int next_pol1 = dp[next_pos][pos2] + distOfPol1;

    int distOfPol2 = 
        abs (pol2[next_pos].first - pol2[pos2].first) + abs (pol2[next_pos].second - pol2[pos2].second);
    int next_pol2 = dp[pos1][next_pos] + distOfPol2;

    if (next_pol1 > next_pol2) {
        tracking.push_back (2);
        trace (pos1, next_pos);
    } else {
        tracking.push_back (1);
        trace (next_pos, pos2);
    }
}
int main () {
    cin.tie (NULL);
    ios::sync_with_stdio (false);

    memset (dp, -1, sizeof(dp));

    cin >> N;
    cin >> W;

    pol1[0] = {1, 1};
    pol2[0] = {N, N};

    for (int i = 1; i <= W; i++) {
        int a, b;
        cin >> a >> b;
        pol1[i] = {a, b};
        pol2[i] = {a, b};
    }
    cout << solution (0, 0) << "\n";
    trace (0, 0);
    for (int a : tracking)
        cout << a << "\n";
    return 0;
}