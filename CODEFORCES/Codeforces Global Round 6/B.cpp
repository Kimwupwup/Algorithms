/**

 * Codeforces Global Round 6
 * B. Dice Tower
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
    while (T--) {
        long long n;
        cin >> n;

        if (n < 15)
            cout << "NO\n";
        else {
            if (n % 14 <= 6 && n % 14 >= 1)
            cout << "YES\n";
        else
            cout << "NO\n";
        }


    }

    return 0;
}
