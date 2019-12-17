/**
 * SW Expert 8840번 - 아바바바
 * 
 * 단순 계산
 * 
 * */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        long long n;
        cin >> n;

        long long ret = ((n - 1) / 2 * (1 + n - 2)) / 2;
        cout << "#" << test_case << " " << ret << "\n";
    }
}