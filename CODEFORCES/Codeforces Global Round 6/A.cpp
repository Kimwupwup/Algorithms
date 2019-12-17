/**

 * Codeforces Global Round 6
 * A. Competitive Programmer
 * 
 * */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--) {
        string str;
        bool isFound = false;

        cin >> str;
        
        int ret = 0;
        int isZero = 0;
        bool isDouble = false;
        int isThree = 0;
        sort(str.begin(), str.end());
        for (int i = 0; i < str.size(); i++) {
            ret += (str[i] - '0');

            if ((str[i] - '0') % 3 == 0 && str[i] != '0')
                isThree++;
            if (str[i] == '0')
                isZero++;
            if ((str[i] - '0') % 2 == 0 && str[i] != '0')
                isDouble = true;
        }

        if (str[0] == '0' && str[str.size() - 1] == '0') {
            cout << "red\n";
            continue;
        }
        
        if (ret % 3 == 0) {
            if (isZero) {
                if (isDouble || isZero > 1) {
                    cout << "red\n";
                    continue;
                }
            }
        }
        cout << "cyan\n";
        
    }
    return 0;
}