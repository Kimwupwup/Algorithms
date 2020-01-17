/**
 * 백준 1759번 - 암호 만들기
 * 
 * TODO:
 * 완전 탐색, 백트래킹
 * */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 16;
int l, c;
vector<char> v;

void solve(string str, int idx, int cnt) {
    if (cnt == l) {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
                cnt0++;
            } else {
                cnt1++;
            }
        }
        if (cnt0 >= 1 && cnt1 >= 2) {
            cout << str << "\n";
            return;
        }
    }

    for (int i = idx; i < c; i++) {
        str.push_back(v[i]);
        solve(str, i + 1, cnt + 1);
        str.pop_back();
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> l >> c;
    for (int i = 0; i < c; i++) {
        char temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    solve("", 0, 0);

    return 0;
}