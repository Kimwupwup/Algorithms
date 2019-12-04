/**
 * 백준 10942번 - 펠린드롬
 * 
 * */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int MAX = 2001;
vector<pair<int, int>> p;
int N, M;
int matrix[MAX];
int dp[MAX][MAX];

int fellin (int start, int end) {
    if (start == end)
        return 1;
    else if (start + 1 == end)
        if (matrix[start] == matrix[end])
            return 1;
        else
            return 0;
    
    int &ret = dp[start][end];

    if (ret != -1)
        return ret;

    ret = fellin (start + 1, end - 1);
    if (ret && matrix[start] == matrix[end]) {
        ret = 1;
    } else {
        ret = 0;
    }
    return ret;
}

int main () {
    cin.tie (NULL);
    ios::sync_with_stdio (false);
    memset (dp, -1, sizeof(dp));

    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> matrix[i];
    
    cin >> M;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        p.push_back({a, b});
    }
    for (pair<int, int> a : p)
        cout << fellin (a.first, a.second) << "\n";
    return 0;
}