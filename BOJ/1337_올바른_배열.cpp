/**
 * 백준 1337번 - 올바른 배열
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
const int MAX = 10000;
set<int> s;
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        s.insert(temp);
    }
    set<int>::iterator iter;
    int ret = INF;
    for (iter = s.begin(); iter != s.end(); iter++) {
        int temp = *iter;
        int cnt = 0;
        for (int i = 1; i <= 4; i++) {
            if (s.find(temp + i) == s.end()) {
                cnt++;
            }
        }
        ret = min(ret, cnt);
    }
    cout << ret << "\n";
    return 0;
}