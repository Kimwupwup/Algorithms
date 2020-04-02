/**
 * 백준 1786번 - 찾기
 * 
 * TODO:
 * KMP, 문자열 매칭
 * */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPi(string P) {
    int m = P.size();
    int j = 0;

    vector<int> pi(m, 0);

    for (int i = 1; i < m; i++) {
        while (j > 0 && P[i] != P[j]) j = pi[j - 1];
        if (P[i] == P[j]) pi[i] = ++j;
    }
    return pi;
}

vector<int> KMP(string T, string P) {
    int n = T.size(), m = P.size();
    int j = 0;

    vector<int> ret;
    vector<int> pi = getPi(P);

    for (int i = 0; i < n; i++) {
        while (j > 0 && T[i] != P[j]) j = pi[j - 1];
        if (T[i] == P[j]) {
            if (j == m - 1) {
                ret.push_back(i - m + 1);
                j = pi[j];
            }
            else {
                j++;
            }
        }
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string T, P;
    getline(cin, T);
    getline(cin, P);

    vector<int> ret = KMP(T, P);

    cout << ret.size() << "\n";
    for (int a : ret)
        cout << a + 1 << " ";
    return 0;
}