/**
 * SW Expert 8673번 - 코딩 토너먼트1
 * 
 * 단일 배열
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<int> v;
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        v.clear();
        int n, ret = 0;
        cin >> n;
        for (int i = 0; i < pow(2, n); i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        int cur = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < pow(2, n - i); j += 2) {
                ret += abs(v[j] - v[j + 1]);
                v[cur] = max(v[j], v[j + 1]);                
                cur++;
            }
            cur = 0;
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
    return 0;
}