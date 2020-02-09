#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string n;
        cin >> n;

        long long ret = 0;
        while (stoi(n)) {
            int num = stoi(n);

            int fir = int((n[0] - '0') * ceil(pow(10, n.size() - 1)));

            ret += fir;
            num -= fir;
            num += int(floor(double(fir) / 10.0));
            n.clear();
            n = to_string(num);
        }
        cout << ret << "\n";
    }

    return 0;
}