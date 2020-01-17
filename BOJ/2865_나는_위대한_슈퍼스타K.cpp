/**
 * 백준 2865번 - 나는 위대한 슈퍼스타K
 * 
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 101;
int n, m, k;
vector<vector<double>> v;
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;
    v.resize(n + 1);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int a;
            double b;
            cin >> a >> b;
            v[a].push_back(b);
        }
    }

    vector<double> ret;
    for (int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), greater<double>());
        ret.push_back(v[i][0]);
    }
    sort(ret.begin(), ret.end(), greater<double>());

    double answer = 0.;
    for (int i = 0; i < k; i++) 
        answer += ret[i];
    printf("%.1f\n", answer);
    
    return 0;
}