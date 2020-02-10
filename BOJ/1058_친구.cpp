/**
 * 백준 1058번 - 친구
 * 
 * TODO:
 * 플로이드 와샬
 * */
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int MAX = 50;
int n;

vector<int> matrix[MAX];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    
    for (int i = 0; i < n; i++)
        matrix[i].resize(n, INF);

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++)
            if (str[j] == 'Y') matrix[i][j] = 1;
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (matrix[i][j] > matrix[i][k] + matrix[k][j])
                    matrix[i][j] = matrix[i][k] + matrix[k][j];
            }
        }
    }
    int ret = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if (matrix[i][j] <= 2) sum++;
        }
        ret = max(ret, sum);
    }
    cout << ret << "\n";
    return 0;
}