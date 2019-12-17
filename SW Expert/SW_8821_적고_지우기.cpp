/**
 * SW Expert 8821번 - 적고 지우기
 * 
 * map 혹은 bitmask 처리하면 될듯
 * */

#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        int chk = 1 << 10;
        string str;
        cin >> str;

        for (int i = 0; i < str.size(); i++) {
            int mask = 1 << (str[i] -'0');
            if (mask & chk) {
                chk -= mask;
            } else {
                chk += mask;
            }
        }
        int ret = 0;
        for (int i = 0; i < 10; i++) {
            int mask = 1 << i;
            if (mask & chk)
                ret++;
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
    return 0;
}