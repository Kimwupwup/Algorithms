/**
 * 백준 2789번 - 유학금지
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string str = "CAMBRIDGE";
    bool path[26];
    memset(path, false, sizeof(path));
    for (int i = 0; i < str.size(); i++) {
        path[str[i] - 'A'] = true;
    }

    string temp;
    cin >> temp;

    for (int i = 0; i < temp.size(); i++) {
        if (path[temp[i] - 'A'])
            temp[i] = '.';
    }

    for (char it : temp)
        if (it != '.')
            cout << it;
    

    return 0;
}