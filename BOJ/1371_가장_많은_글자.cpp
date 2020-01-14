/**
 * 백준 1371번 - 가장 많은 글자
 * 
 * TODO:
 * 문자열 처리
 * */
#include <bits/stdc++.h>
using namespace std;

int alphabet[26];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    
    string str;
    while (cin >> str) {
        for (int i = 0; i < str.size(); i++) {
            if (str[i] >= 'a' && str[i] <= 'z')
                alphabet[str[i] - 'a']++;
        }
        str.clear();
    }

    int maxi = 0;
    for (int i = 0; i < 26; i++)
        if (maxi < alphabet[i])
            maxi = alphabet[i];
    for (int i = 0; i < 26; i++) 
        if (maxi == alphabet[i])
            cout << (char)(i + 'a');
    cout << "\n";
    return 0;
}