/**
 * 백준 1806번 - 부분합
 * 
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 100000;
const int INF = 987654321;

int matrix[MAX];
int n;
long long m;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> matrix[i];
    
    long long sum = 0;
    int length = 0;
    int idx = 0;
    int ret = INF;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        sum += matrix[i];
        length++;
        v.push_back(matrix[i]);

        while (sum >= m) {
            ret = min(ret, length);
            sum -= v[idx++];
            length--;
        }
    }
    
    if (ret == INF)
        cout << 0 << "\n";
    else 
        cout << ret << "\n";
    return 0;
}