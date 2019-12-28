/**
 * http://codeforces.com/contest/1283/problem/E
 * Codeforces Round #611 Div. 3 (20191229)
 * E. New Year Parties
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

const int MAX = 2 * 500000;
int n;
vector<int> house;
int dp[MAX];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        house.push_back(temp);
    }

    sort(house.begin(), house.end());

    return 0;   
}