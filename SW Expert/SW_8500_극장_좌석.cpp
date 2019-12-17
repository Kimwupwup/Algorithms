/**
 * SW Expert 8500번 - 극장 좌석
 * 
 * */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> v;

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        v.clear();
        
        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        int ret = 0;
        for (int i = 0; i < n; i++) {
            ret += v[i];
            ret += 1;
        }
        ret += *(--v.end());
        cout << "#" << t << " " << ret << "\n";
    }
    return 0;
}