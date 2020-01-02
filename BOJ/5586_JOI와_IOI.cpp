/**
 * 백준 5586번 - JOI와 IOI
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a = 0, b = 0;

    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == 'I' && str[i - 1] == 'O' && i >= 2) {
            if (str[i - 2] == 'J') a++;
            else if (str[i - 2] == 'I')b++;
        }
    }
    cout << a << "\n";
    cout << b << "\n";
    return 0;
}