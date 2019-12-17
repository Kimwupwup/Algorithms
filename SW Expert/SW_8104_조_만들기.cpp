/**
 * SW Expert 8104번 - 조 만들기
 * 1    2   3   4   5   6
 * 12   11  10  9   8   7
 * 13   14  15  16  17  18
 * ...
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int n, k;
        cin >> n >> k;

        int ret = 0;
        int current = 0;
        for (int j = 0; j < n; j++) {
            if (j % 2 == 0) {
                current += 1;
                ret += current;
            } else {
                current += k * 2 - 1;
                ret += current;
            }
        }
        cout << "#" << t << " ";
        if (n % 2 == 1) {
            for (int i = 0; i < k; i++)
                cout << ret + i << " ";
        } else {
            for (int i = 0; i < k; i++)
                cout << ret << " ";
        }
        cout << "\n";
    }
    return 0;
}