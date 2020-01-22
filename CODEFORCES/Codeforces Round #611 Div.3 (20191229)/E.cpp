/**
 * http://codeforces.com/contest/1283/problem/E
 * Codeforces Round #611 Div. 3 (20191229)
 * E. New Year Parties
 * 
 * */
#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v, cnt;

int solvemin() {
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (!cnt[i])
            continue;
        ret++;
        i += 2;
    }
    return ret;
}

int solvemax() {
    int ret = 0;
    int dist = 2;
    bool right = false;

    for (int i = 0; i < n; i++) {
        if (!cnt[i]) {
            dist++;
            continue;
        }

        int j = i;
        int sum = 0;
        while (j < n && cnt[j]) {
            sum += cnt[j];
            j++;
        }

        // defalut
        ret += j - i;

        // left side
        if (sum > j - i && (!right || dist > 1)) {
            ret++;
            sum--;
        }

        // right side
        right = false;
        if (sum > j - i) {
            right = true;
            ret++;
        }

        // update
        i = j - 1;
        dist = 0;
    }
    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    v.resize(n);
    cnt.resize(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cnt[v[i] - 1]++;
    }

    cout << solvemin() << " " << solvemax() << "\n";
    
    return 0;
}