/**
 * 백준 1212번 - 8진수 2진수
 * 
 * TODO:
 * 수학, 비트마스크
 * */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    cout.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    vector<int> v;

    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        v.push_back(str[i] - '0');
    }
    if (str == "0") {
        cout << 0 << "\n";
        return 0;
    }

    vector<int> ret;
    for (int i = 0; i < v.size(); i++) {
        for (int j = 2; j >= 0; j--) {
            ret.push_back((v[i] & (1 << j)) ? 1 : 0);
        }
    }
    int idx = 0;
    while (ret[idx] == 0)
        idx++;

    for (int i = idx; i < ret.size(); i++) {
        cout << ret[i];
    }
    return 0;
}