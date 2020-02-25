/**
 * 백준 9613번 - GCD 합
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 100;
vector<int> v;
int t, n;

int GCD(int a, int b) {
    if (a % b == 0) return b;
    return GCD(b, a % b);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> t;
    while (t--) {
        v.clear();
        cin >> n;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            v.push_back(temp);
        }

        long long ret = 0;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                ret += GCD(v[i], v[j]);
            }
        }
        cout << ret << "\n";
    }
    return 0;
}