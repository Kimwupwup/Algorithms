/**
 * http://codeforces.com/contest/1283/problem/C
 * Codeforces Round #611 Div. 3 (20191229)
 * C. Friends and Gifts
 * 
 * */

#include <bits/stdc++.h>
using namespace std;

const int MAX = 2 * 500000;
int n;
vector<int> v;
vector<int> zeros;
vector<int> noCall;
vector<int> ret;
bool matrix[MAX + 1];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }
    
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            zeros.push_back(i + 1);
        }        
        else {            
            matrix[v[i]] = true;
        }
    }

    for (int i = 1; i <= n; i++) {
        if (!matrix[i]) {
            noCall.push_back(i);
        }
    }

    for (int i = 0; i < zeros.size(); i++) {
        if (noCall[i] == zeros[i]) {
            int temp = noCall[i];
            noCall[i] = noCall[(i + 1) % zeros.size()];
            noCall[(i + 1) % zeros.size()] = temp;
        }
    }

    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] != 0) {
            cout << v[i] << " ";
        } else {
            cout << noCall[idx] << " ";
            idx++;
        }
    }
    return 0;
}