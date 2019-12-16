/**
 * 백준 2902번 - KMP는 왜 KMP일까?
 * 
 * */

#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string input;
    string ret = "";
    cin >> input;
    ret += input[0];
    for (int i = 1; i < input.size(); i++) {
        if (input[i] == '-') {
            ret += input[i + 1];
            i++;
        }
    }
    cout << ret << endl;
    return 0;
}