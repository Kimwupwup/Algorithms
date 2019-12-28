/**
 * Educational Codeforces Round 78
 * A. Shuffle Hashing
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int matrix[26];
    int temp[26];
    int T;
    cin >> T;

    while (T--) {
        memset(matrix, 0, sizeof(matrix));

        string p;
        string tmp_p;

        cin >> p;
        cin >> tmp_p;

        int cnt = 0;
        for (int i = 0; i < p.size(); i++) {
            matrix[p[i] - 'a']++;
        }

        int dist = tmp_p.size() - p.size();
        if (dist < 0) {
            cout << "NO\n";
            continue;
        }
        bool isTrue = true;
        for (int i = 0; i <= dist; i++) {
            memset(temp, 0, sizeof(temp));
            isTrue = true;
            for (int j = i; j < tmp_p.size() - (dist - i); j++) {
                temp[tmp_p[j] - 'a']++;
            }

            for (int j = 0; j < 26; j++) {
                if (matrix[j] != temp[j]) {
                    isTrue = false;
                    break;
                }
            }
            if (isTrue)
                break;
        }
        if (isTrue)
            cout << "YES\n";
        else 
            cout << "NO\n";
    }

    return 0;
}