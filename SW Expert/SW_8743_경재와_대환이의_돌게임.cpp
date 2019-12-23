/**
 * SW Expert 8743번 - 경재와 대환이의 돌게임
 * 
 * */

#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        long long r, b;
        cin >> r >> b;
        if (abs(r - b) <= 1)
            cout << "#" << t << " " << "DH" << "\n";
        else 
            cout << "#" << t << " " << "KJ" << "\n";
    }
    return 0;
}