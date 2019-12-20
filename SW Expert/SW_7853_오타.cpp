/**
 * SW Expert 7853번 - 오타
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const long long MAX = 1000000007;
bool matrix[26];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string str;
        cin >> str;

        long long ret = 1;

        for (int i = 0; i < str.size(); i++) {
            int cnt = 0;
            memset(matrix, false, sizeof(matrix));

            for (int j = -1; j < 2; j++) {
                if (i + j < 0 || i + j >= str.size())
                    continue;
                if (!matrix[str[i + j] - 'a']) {
                    matrix[str[i + j] - 'a'] = true;
                    cnt++;
                }
            }
            ret = ret * cnt % MAX;
        }
        cout << "#" << t << " " << ret % MAX << "\n";
    }
    return 0;
}