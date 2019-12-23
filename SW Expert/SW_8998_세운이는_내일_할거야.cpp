/**
 * SW Expert 8998번 - 세운이는 내일 할거야
 * 
 * */
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<pair<int, int>> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        v.clear();
        int n;
        cin >> n;
        v.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].second >> v[i].first;
        }

        sort(v.begin(), v.end(), greater<pair<int, int>>());

        int ret = v[0].first - v[0].second;
        for (int i = 0; i < n - 1; i++) {
            if (v[i + 1].first < ret)
                ret = v[i + 1].first - v[i + 1].second;
            else {
                ret -= v[i + 1].second;
            }
        }
        cout << "#" << t << " " << ret << "\n";
    }
    return 0;
}