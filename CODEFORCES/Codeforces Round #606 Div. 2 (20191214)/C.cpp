/**
 * http://codeforces.com/contest/1277/problem/C
 * Codeforces Round #606(20191214)
 * C. As Simple as One and Two
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

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<int> v;

    int T;
    cin >> T;
    while (T--) {
        v.clear();
        string one = "one";
        string two = "two";
        string twone = "twone";

        string str;
        cin >> str;
        size_t size = 0;
        while (true) {
            size = str.find(twone, size);
            if (size == string::npos) {
                break;
            }
            v.push_back(size + 2);
            str[size + 2] = '?';
            size += 1;
        }

        size = 0;
        while (true) {
            size = str.find(one, size);
            if (size == string::npos) {
                break;
            }
            v.push_back(size + 1);
            str[size + 1] = '?';
            size += 1;
        }
        
        size = 0;
        while (true) {
            size = str.find(two, size);
            if (size == string::npos) {
                break;
            }
            v.push_back(size + 1);
            str[size + 1] = '?';
            size += 1;
        }
        cout << v.size() << "\n";
        for (int a : v)
            cout << a + 1 << " ";
        cout << "\n";
    }
    return 0;
}