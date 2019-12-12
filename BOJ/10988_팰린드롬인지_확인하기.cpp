/**
 * 백준 10988번 - 팰린드롬인지 확인하기
 * 
 * 팰린드롬 문제 DP가 아니고
 * 주어진 단어가 대칭구조 인지 아닌지만 확인하면 됨
 * 
 * */

#include <iostream>
#include <string>

using namespace std;

string str;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> str;
    for (int i = 0; i <= str.size() / 2; i++) {
        if (str[i] != str[str.size() - i - 1]) {
            cout << 0 << "\n";
            return 0;
        }
    }
    cout << 1 << "\n";
    return 0;
}