/**
 * 백준 1919번 - 애너그램 만들기
 * 
 * */
#include <bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;

int matrix[26];
int other[26];
string a, b;
int ret = 0;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> a;
    cin >> b;
    forn (i, a.size()) {
       matrix[a[i] - 'a']++;
    }

    forn (i, b.size()) {
        if (matrix[b[i] - 'a'])
            matrix[b[i] - 'a']--;
        else
            other[b[i] - 'a']++;
    }
    
    forn(i, 26)
        ret += matrix[i] + other[i];
    cout << ret << "\n";
    return 0;
}