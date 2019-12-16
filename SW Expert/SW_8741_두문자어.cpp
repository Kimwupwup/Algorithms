/**
 * SW Expert 8741번 - 두문자어
 * string 3개 받고 각 string 첫 글자를 대문자로
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
        string a[3];
        for (int i = 0; i < 3; i++) {
            cin >> a[i];
        }
        string ret;
        for (int i = 0; i < 3; i++) {
            ret += toupper(a[i][0]);
        }
        cout << "#" << test_case << " " << ret << "\n";
    }
    return 0;
}