/**
 * 백준 5598번 - 카이사르 암호
 * 
 * TODO:
 * 아스키 코드 이용 % 26하면 순환구조
 * */
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        str[i] = str[i] - 3;
        if (str[i] < 'A')
            str[i] = 'Z' - ('A' - str[i]) + 1;
    }
    cout << str << "\n";
    return 0;
}