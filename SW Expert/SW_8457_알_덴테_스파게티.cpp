/**
 * SW Expert 8457번 - 알 덴테 스파케티
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

        int N, B, E;
        cin >> N >> B >> E;

        v.resize(N);

        for (int i = 0; i < N; i++) {
            cin >> v[i];
        }

        int ret = 0;
        for (int i = 0; i < N; i++) {
            if (B % v[i] <= E || v[i] - (B % v[i]) <= E)
                ret++;
        }
        cout << "#" << t << " " << ret << "\n";
    }
    return 0;
}