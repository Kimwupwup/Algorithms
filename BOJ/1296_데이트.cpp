/**
 * 백준 1296번 - 데이트
 * 
 * TODO:
 * ...
 * */
#include <bits/stdc++.h>
using namespace std;
string str;
vector<string> v;
int matrix[26];
int temp[26];
int n;

struct cmp {
    bool operator() (const pair<int, string> &a, const pair<int, string> &b) const {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
};

set<pair<int, string>, cmp> sset;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> str;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    for (int i = 0; i < str.size(); i++)
        matrix[str[i] - 'A']++;

    int idx = 0;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        memset(temp, 0, sizeof(temp));
        for (int j = 0; j < v[i].size(); j++) {
            temp[v[i][j] - 'A']++;
        }
        int sum[6];
        memset(sum, 0, sizeof(sum));
        sum[0] = (matrix['L' - 'A'] + temp['L' - 'A']) + (matrix['O' - 'A'] + temp['O' - 'A']);
        sum[1] = (matrix['L' - 'A'] + temp['L' - 'A']) + (matrix['V' - 'A'] + temp['V' - 'A']);
        sum[2] = (matrix['L' - 'A'] + temp['L' - 'A']) + (matrix['E' - 'A'] + temp['E' - 'A']);
        sum[3] = (matrix['O' - 'A'] + temp['O' - 'A']) + (matrix['V' - 'A'] + temp['V' - 'A']);
        sum[4] = (matrix['O' - 'A'] + temp['O' - 'A']) + (matrix['E' - 'A'] + temp['E' - 'A']);
        sum[5] = (matrix['V' - 'A'] + temp['V' - 'A']) + (matrix['E' - 'A'] + temp['E' - 'A']);
        int s = 1;
        for (int a : sum)
            s = (s * a) % 100;
        sset.insert(make_pair(s, v[i]));
    }

    cout << sset.begin()->second << "\n";
    return 0;
}