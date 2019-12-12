/**
 * 백준 17404번 - RGB거리 2
 * 
 * DP 알고리즘
 * dp[i][j] : 현재 i 집일 때, j 색을 칠한 경우, 최소비용
 * */

#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 1002;
const int RGB = 3;
const int INF = 987654321;

int n;
int matrix[MAX][RGB];
int dp[MAX][3];

int solution(int current, int rgb) {
    if (current == n - 1) 
        return 0;
    
    int &ret = dp[current][rgb];
    if (ret != -1)
        return ret;
    ret = INF;

    if ()
}
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    
    for (int i = 0; i < 3; i++)
        matrix[n][i] = matrix[0][i];
    

}