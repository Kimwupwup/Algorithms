/**
 * Educational Codeforces Round 80
 * B. 
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    long long T;
    cin >> T;

    while (T--) {
        long long A, B;
        long long ret;
        string str;
        long long cnt = 0;
        cin >> A >> B;
        
        for (long long i = 1; i <= A; i++) {
            long long left = 1;
            long long right = B;
            long long mid;
            while (left <= right) {
                mid = (left + right) / 2;
                ret = (i * mid) + i + mid;

                str = to_string(i) + to_string(mid);

                if (ret > stoll(str)) {
                    right = mid - 1;
                }
                else if (ret < stoll(str)) {
                    left = mid + 1;
                }
                if (i == 1)
                    cout << i << " " << mid << " " << ret << " " << str << "\n";
                if (ret == stoll(str)) {
                    cnt++;
                    break;
                }
            }
        }
        cout << cnt << "\n";
    }

    return 0;
}