/**
 * http://codeforces.com/contest/1277/problem/B
 * Codeforces Round #606(20191214)
 * B. Make Them Odd
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <cstring>
#include <set>

using namespace std;

set<int> s;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {

        s.clear();
        int ret = 0;

        int n;
        cin >> n;       

        for (int i = 0; i < n; i++) {
            int num;
            cin >> num;
            s.insert(num);
        }

        
        while (!s.empty()) {            
            set<int>::iterator iter;
            iter = --s.end();
            int num = *iter;        
            s.erase(iter);

            if (num % 2 == 0) {
                num /= 2;
                ret++;
                s.insert(num);
            }            
        }
        cout << ret << "\n";
    }
    return 0;
}