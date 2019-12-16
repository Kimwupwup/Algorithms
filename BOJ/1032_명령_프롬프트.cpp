/**
 * 백준 1032번 - 명령 프롬프트
 * 
 * */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int matrix[26];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n;
    vector<string> v;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        v.push_back(temp);    
    }
    bool isFound = false;
    for (int i = 0; i < v[0].size(); i++) {
        for (int j = 0; j < n; j++) {
            isFound = false;
            if (v[0][i] != v[j][i]) {
                isFound = true;
                cout << "?";
                break;
            }
        }
        if (isFound == false)
            cout << v[0][i];
    }
    return 0;
}