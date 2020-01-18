/**
 * 백준 1107번 - 리모컨
 * 
 * */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 500001;
int n, m;
int mask = (1 << 10);

int cal_size(int i) {
    if (i == 0) {
        if (!((1 << 0) & mask)) {
            return 1;
        }
    }

    int ret = 0;
    while (i) {
        int cur = i % 10;
        if (!((1 << cur) & mask)) {
            ret++;
        } else {
            return 0;
        }
        i /= 10;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int tmp;
        cin >> tmp;
        mask = mask | (1 << tmp);
    }
    int ret = abs(n - 100);

    for (int i = 0; i < 1000000; i++) {
        if (cal_size(i)) {
            ret = min(ret, cal_size(i) + abs(i - n));
        }
    }
    cout << ret << "\n";
    return 0;
}