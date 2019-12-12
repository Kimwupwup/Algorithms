/**
 * 백준 1764번 - 듣보잡
 * 
 * */

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> ret;
map<string, bool> mapp;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        mapp[temp] = true;
    }
    for (int i = 0; i < m; i++) {
        string temp;
        cin >> temp;
        if (mapp.find(temp) != mapp.end())
            ret.push_back(temp);
    }
    sort(ret.begin(), ret.end());
    cout << ret.size() << "\n";
    for (string a : ret)
        cout << a << "\n";
    return 0;
}