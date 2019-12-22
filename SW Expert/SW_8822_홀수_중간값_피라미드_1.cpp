/**
 * SW Expert 8822번 - 홀수 중간값 피라미드 1
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()  {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int n, x;
        cin >> n >> x;
        if (x == 1 || x == 2 * n - 1)
            cout << "#" << t << " " << 0 << "\n";
        else 
            cout << "#" << t << " " << 1 << "\n";
    }
    return 0;
}