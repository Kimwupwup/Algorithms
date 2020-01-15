/**
 * 백준 3486번 - Adding Reversed Numbers
 * 
 * TODO:
 * 그리디
 * */
#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string a, b, str_c;
        int c;
        cin >> a >> b;

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        c = stoi(a) + stoi(b);
        
        str_c = to_string(c);
        reverse(str_c.begin(), str_c.end());

        cout << stoi(str_c) << "\n";
    }
    

    return 0;
}