/**
 * SW Expert 8338번 - 계산기
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ret = 0;
vector<int> v;

void solution(int idx, int current) {
    if (idx == v.size()) {
        if (ret < current)
            ret = current;
        return;
    }

    for (int i = 0; i < 2; i++) {
        int next = current;
        if (i == 0) {
            next += v[idx];
        }
        else {
            next *= v[idx];
        }
        solution(idx + 1, next);
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        v.clear();
        ret = 0;
        int n;
        cin >> n;

        v.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        solution(0, 0);
        cout << "#" << t << " " << ret << "\n";
    }
    return 0;
}