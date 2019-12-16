/**
 * SW Expert 8556번 - 북북서
 * 
 * string 구분, 기약분수(최대공약수)
 * */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int GCD(int a, int b) {
    if (a % b == 0)
        return b;
    return GCD(b, a % b);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    vector<char> v;

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        v.clear();
        string str;
        cin >> str;
        for (int i = str.size() - 1; i >= 0; i--) {
            if (str[i] == 'n') {
                v.push_back('n');
            } else if (str[i] == 'w') {
                v.push_back('w');
            }
        }

        int po = pow(2, v.size() - 1);
        int ret = 0;
        if (v[0] == 'w')
            ret = 90 * po;
        else 
            ret = 0;
        
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == 'w') {
                ret += (90 * po / pow(2, i));
            } else {
                ret -= (90 * po / pow(2, i));
            }
        }

        int a = GCD(ret, po);
        ret /= a;
        po /= a;
        if (po == 1) {
            cout << "#" << test_case << " " << ret << "\n";
        }
        else {
            cout << "#" << test_case << " " << ret << "/" << po << "\n";
        }
    }
    return 0;
}