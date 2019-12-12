/**
 * 백준 10987번 - 모음의 개수
 * */

#include <iostream>
#include <string>

using namespace std;

string str;
int cnt = 0;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> str;
    for (int i = 0 ; i < str.size(); i++)
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u')
            cnt++;

    cout << cnt << "\n";
    return 0;
}