/**
 * 백준 17404번 - RGB거리 2
 * 
 * TODO:
 * DP 알고리즘
 * dp[i][j] : 현재 i 집일 때, i - 1 집까지 칠하고 지금 j 색을 칠한 경우, 최소비용
 * 
 * 1. 첫 집에 3개의 색 중 하나를 칠한다.
 * 2. 첫 집색을 칠한 비용을 추가한다. 나머지 색상에 대해서는 INF로 설정한다. 
 * (첫 집에 색이 이미 정해져 있으므로, 다음 집 연산에 들어가면 안되기 때문이다. 
 * 최솟값을 찾고 있기때문에 dp[0][j]=0 으로 설정하면 다음 연산에 채택되기 때문이다.)
 * 3. dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + matrix[i][0];
 * (dp[i][0]는 0 색을 칠할 때 i 까지의 최소 비용이므로, 
 * i - 1 까지의 1, 2 색(이웃끼리 겹치면 안된다.)의 최솟값에 
 * i 집의 0 색의 비용을 더해주면 된다.)
 * 4. 이를 0, 1, 2 색을 실행한다.
 * 
 * 백준 1149번 - RGB 거리 문제와 유사
 * 하지만 1149번 문제는 직선구조로 되어있기 때문에,
 * dp[0][j]를 첫 집의 각색의 비용을 넣고 시작하면 된다.
 * */
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int INF = 987654321;
const int MAX = 1001;
int n;
int matrix[MAX][3];
int dp[MAX][3];
int ret = INF;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 3; j++) 
            cin >> matrix[i][j];
    
    // 직선 구조가 아닌 순환구조이므로, 첫 집에 3색을 한번씩 실행시켜 최소값을 찾는다.
    for (int i = 0; i < 3; i++) {

        // 첫 집에 지금 칠할 색의 비용은 그대로, 나머지는 INF
        // dp[0][j] = 0이면, dp[1][j]연산에서 0이 무조건 채택되기 때문에 INF로 설정한다.
        for (int j = 0; j < 3; j++) {
            if (i == j) dp[0][j] = matrix[0][j];
            else dp[0][j] = INF;
        }

        for (int j = 1; j < n; j++) {
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + matrix[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + matrix[j][1];
            dp[j][2] = min(dp[j - 1][0], dp[j - 1][1]) + matrix[j][2];
        }

        // 다시 첫 집으로 돌아가 마지막 집과 값을 비교하여, 작은 값을 답으로 한다.
        // 첫 집은 칠해져 있으므로 제외하고 나머지 두 색을 대비
        for (int j = 0; j < 3; j++) {
            if (i == j) continue;
            else {
                ret = min(ret, dp[n - 1][j]);
            }
        }
    }    
    cout << ret << "\n";
    return 0;
}