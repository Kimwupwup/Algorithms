/**
 * 백준 10799번 - 쇠막대기
 * 
 * TODO:
 * 스택
 * */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<char> v;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    int cnt = -1, ret = 0;
    cin >> str;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(') cnt++;
        else if (str[i - 1] == '(') {
            ret += cnt;
            cnt--;
        }
        else {
            cnt--;
            ret++;
        }
    }
    cout << ret << "\n";
    return 0;
}