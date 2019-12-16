/**
 * SW Expert 8658번 - Summation
 * 
 * vector, sort, string
 * */

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        vector<int> v;

        for (int i = 0; i < 10; i++) {
            string str;
            cin >> str;
            int temp = 0;
            for (int j = 0; j < str.size(); j++)
                temp += (str[j] - '0');
            v.push_back(temp);
        }
        sort(v.begin(), v.end());

        cout << "#" << test_case << " " << v[v.size() - 1] << " " << v[0] << "\n";
    }
    return 0;
}