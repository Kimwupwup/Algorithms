/**
 * http://codeforces.com/contest/1283/problem/D
 * Codeforces Round #611 Div. 3 (20191229)
 * D. Christmas Trees
 * 
 * */

#include <bits/stdc++.h>

using namespace std;

int n, m;
long long ret = 0;
vector<int> ret_vector;
queue<pair<int, int>> q;
set<int> s;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        s.insert(temp);
        q.push(make_pair(temp, temp));
    }

    while (!q.empty()) {
        int origin = q.front().first;
        int current = q.front().second;
        q.pop();

        if (s.find(current - 1) == s.end()) {
            m--;
            s.insert(current - 1);
            ret += abs(origin - (current - 1));
            q.push(make_pair(origin, current - 1));
            ret_vector.push_back(current - 1);
        }
        if (m == 0)
            break;
        if (s.find(current + 1) == s.end()) {
            m--;
            s.insert(current + 1);
            ret += abs(origin - (current + 1));
            q.push(make_pair(origin, current + 1));
            ret_vector.push_back(current + 1);
        }
        if (m == 0)
            break;
    }
    cout << ret << "\n";
    for (int a : ret_vector)
        cout << a << " ";
        
    return 0;   
}