/**
 * Codeforces round #605 20191212
 * C. Yet Another Broken Keyboard
 * 
 * */
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int n, m;
string str;
bool alpha[26];
int ret = 0;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    cin >> str;
    for (int i = 0; i < m; i++) {
        char temp;
        cin >> temp;
        alpha[temp - 'a'] = true;
    }
    int start = 0;
    int end = 0;
    for (int i = 0; i < n; i++) {
        bool is = false;
        if (alpha[str[i] - 'a']) {
            end = i;
        } else {
            for (int i = 1; i <= end - start + 1; i++) {
                ret += end - start + 1 - (i - 1);
            }
            start = i + 1;
            end = i + 1;
        }
    }
    cout << ret << "\n";
    return 0;
}