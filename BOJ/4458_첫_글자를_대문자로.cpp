/**
 * 백준 4458번 - 첫 글자를 대문자로
 * 
 * TODO:
 * 문자열 처리
 * */
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    cin.ignore();

    while (N--) {
        string temp;
        getline(cin, temp);
        temp[0] = toupper(temp[0]);
        cout << temp << "\n";
    }

    return 0;
}