/**
 * SW Expert 7964번 - 부먹왕국의 차원 관문
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, m;
        cin >> n >> m;

        v.clear();
        v.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int cnt = 0;
        int ret = 0;
        for (int i = 0; i < n; i++) {
            cnt++;

            if (cnt == m) {
                if (v[i] == 1)
                    cnt = 0;
                else {
                    v[i] = 1;
                    cnt = 0;
                    ret++;
                }
            }
            else {
                if (v[i] == 1)
                    cnt = 0;
            }
        }
        
        cout << "#" << t << " " << ret << "\n";
    }

    return 0;
}