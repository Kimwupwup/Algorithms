/**
 * 백준 1339번 - 단어 수학
 * 
 * TODO:
 * 그리디, 수학(가중치)
 * 백트래킹(string 처리 주의)
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 10;
int matrix[26];

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for (int j = 0; j < str.size(); j++) {
            matrix[str[j] - 'A'] += int(pow(10, str.size() - j - 1));
        }
    }

    
    vector<int> v;
    for (int i = 0; i < 26; i++) 
        if (matrix[i])
            v.push_back(matrix[i]);
    
    int ret = 0;
    int cnt = 9;
    sort(v.begin(), v.end(), greater<int>());
    for (int i = 0; i < v.size(); i++) {
        ret += v[i]*(cnt--);
    }
    cout << ret << "\n";
    return 0;
}