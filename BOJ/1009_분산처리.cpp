/**
 * 백준 1009번 - 분산처리
 * 
 * */
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;

        int idx = 1;
        for (int i = 0; i < b; i++) {
            idx *= a;
            if (idx > 10)
                idx %= 10;
            if (idx == 0) idx = 10;
        }
        cout << idx << "\n";
    }
    return 0;
}