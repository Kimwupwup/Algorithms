/**
 * 백준 1406번 - 에디터
 * 
 * TODO:
 * 구현, list
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 600001;
list<char> l;
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        l.push_back(str[i]);
    }

    list<char>::iterator iter = l.end();
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;

        if (op == 'L') {
            if (iter != l.begin())
                iter--;
        }
        else if (op == 'D') {
            if (iter != l.end())
                iter++;
        }
        else if (op == 'B') {
            if (!l.empty() && iter != l.begin()) {
                iter--;
                l.erase(iter);
                iter--;
                iter++;
            }
        }
        else if (op == 'P') {
            char temp;
            cin >> temp;
            l.insert(iter, temp);
        }
    }
    
    for (iter = l.begin(); iter != l.end(); iter++)
        cout << *iter;
    cout << "\n";
    
    return 0;
}