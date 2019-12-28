/**
 * http://codeforces.com/contest/1283/problem/D
 * Codeforces Round #611 Div. 3 (20191229)
 * D. Christmas Trees
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cstring>

using namespace std;

int n, m;
vector<int> trees;
queue<pair<int, int>> q;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        trees.push_back(temp);
        q.push(make_pair(temp, temp));
    }

    return 0;   
}