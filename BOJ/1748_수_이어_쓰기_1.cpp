/**
 * 백준 1748번 - 수 이어 쓰기 1
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int ret = 0;
    string str;
    cin >> str;

    int n = stoi(str);
    int size = str.size();

    ret += (n - pow(10, size - 1) + 1) * size;
    
    for (int i = size - 1; i > 0; i--) {
        ret += (pow(10, i) - pow(10, i - 1)) * i;
    }
    cout << ret << "\n";
    return 0;
}