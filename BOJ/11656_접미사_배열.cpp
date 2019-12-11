/**
 * 백준 11656번 - 접미사 배열
 * 
 * 
 * */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string str, temp;
vector<string> v;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> str;

    for (int i = 0; i <str.size(); i++) {
        
        v.push_back(str.substr(i));
    }
    sort(v.begin(), v.end());
    for (string a : v)
        cout << a << "\n";

    return 0;
}