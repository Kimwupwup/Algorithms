/**
 * 백준 2512번 - 예산
 * 
 * TODO:
 * 이분 탐색
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10000;
int n, m;
vector<int> v;

bool chk(int mid) {
    int sum = 0;
    for (int a : v) {
        sum += a >= mid ? mid : a;
    }
    if (sum <= m) return true;
    else return false;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n);

    int sum = 0;
    int right = 0;
    int left = 0;
    int mid;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];

        if (v[i] > right)
            right = v[i];

    }
    
    cin >> m;
    if (sum <= m) {
        cout << right << "\n";
        return 0;
    }
    
    int ret = 0;
    while (left <= right) {
        mid = (left + right) / 2;
        if (chk(mid)) {
            ret = max(ret, mid);
            left = mid + 1;
        }
        else {
            right = mid - 1;
        }
    }
    cout << ret << "\n";
    return 0;
}