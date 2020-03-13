/**
 * 백준 10953번 - A+B - 6
 * 
 * */
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    while (n--) {
        string str;
        cin >> str;
        cout << (str[0] + str[2] - ('0') * 2) << "\n";
    }

    return 0;
}