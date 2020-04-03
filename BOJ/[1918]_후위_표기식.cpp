/**
 * 백준 1918번 - 후위 표기식
 * 
 * TODO:
 * stack
 * */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str, ret;
    vector<char> v;

    cin >> str;
    
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            ret += str[i];
        }
        else {
            if (str[i] == '(') {
                v.push_back(str[i]);
            }
            else if (str[i] == '*' || str[i] == '/') {
                while (!v.empty() && (v.back() == '*' || v.back() == '/')) {
                    ret += v.back();
                    v.pop_back();
                }
                v.push_back(str[i]);
            }
            else if (str[i] == '+' || str[i] == '-') {
                while (!v.empty() && v.back() != '(') {
                    ret += v.back();
                    v.pop_back();
                }
                v.push_back(str[i]);
            }
            else if (str[i] == ')') {
                while (!v.empty() && v.back() != '(') {
                    ret += v.back();
                    v.pop_back();
                }
                v.pop_back();
            }
        }
    }
    while (!v.empty()) {
        ret += v.back();
        v.pop_back();
    }
    cout << ret << "\n";
    return 0;
}
