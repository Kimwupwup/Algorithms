/**
 * 백준 13414번 - 수강신청
 * 
 * */
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    map<string, int> mp;
    int K, L;
    cin >> K >> L;

    for (int i = 0; i < L; i++) {
        string tmp;
        cin >> tmp;
        mp[tmp] = i;
    }

    vector<pair<int, string>> v;
    for (map<string, int>::iterator iter = mp.begin(); iter != mp.end(); iter++) {
        v.push_back({iter->second, iter->first});
    }
    sort(v.begin(), v.end(), less<pair<int, string>>());
    for (int i = 0; i < min(K, (int)v.size()); i++)
        cout << v[i].second << "\n";
    return 0;
}