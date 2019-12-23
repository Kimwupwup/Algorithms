/**
 * SW Expert 8568번 - 3으로 나눈 순열
 * 
 * */

#include <iostream>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    vector<int> v;

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n;
        cin >> n;
        v.clear();
        v.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] % 3 == (i + 1) % 3)
                continue;
            for (int j = i + 1; j < n; j++) {
                if (v[i] % 3 == (j + 1) % 3) {
                    if (v[j] % 3 == (i + 1) % 3) {
                        int temp = v[i];
                        v[i] = v[j];
                        v[j] = temp;
                        cnt++;
                        break;
                    }
                }
            }
        }
        int ret = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] % 3 != (i + 1) % 3)
                ret++;
        } 
        cnt += (ret / 3) * 2;
        cout << "#" << t << " " << cnt << "\n";
    }
    return 0;
}