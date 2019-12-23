/**
 * SW Expert 7728번 - 다양성 측정
 * 
 * */

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    set<char> s;

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        string str;
        cin >> str;

        s.clear();

        for (int i = 0; i < str.size(); i++) {
            s.insert(str[i]);
        }

        cout << "#" << t << " " << s.size() << "\n";
    }
    return 0;
}