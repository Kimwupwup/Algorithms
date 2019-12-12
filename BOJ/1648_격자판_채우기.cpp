/**
 * 백준 1648번 - 격자판 채우기
 * 
 * https://www.slideshare.net/Baekjoon/baekjoon-online-judge-1648
 * 참고
 * */

#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 14;
const int MOD = 9901;

int N, M;

// 3중 배열이랑 똑같음
int dp[MAX * MAX][1 << MAX];

int solution (int board, int visited) {
    if (board == N * M && visited == 0) 
        return 1;

    if (board >= N * M)
        return 0;
    
    int &ret = dp[board][visited];
    if (ret != -1)
        return ret;
    ret = 0;

    if (visited & 1) {
        ret = solution(board + 1, (visited >> 1));
    } else {
        ret = solution(board + 1, (visited >> 1) | (1 << (M - 1)));
        if ((board % M) != (M - 1) && (visited & (1 << 1)) == 0) {
            ret += solution(board + 2, (visited >> 2));
        }
    }
    return ret % MOD;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    memset (dp, -1, sizeof(dp));

    cout << solution(0, 0) << endl;
    return 0;
}