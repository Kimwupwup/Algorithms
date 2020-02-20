/**
 * 백준 1158번 - 요세푸스 문제
 * 
 * TODO:
 * 구현, iterator, list
 * */
#include <bits/stdc++.h>

using namespace std;

const int MAX = 5000;
list<int> l;
int n, m;

void shift(list<int>::iterator &iter, int cnt) {
    for (int i = 0; i < cnt; i++) {
        iter++;
        if (iter == l.end())
            iter++;
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        l.push_back(i);
    
    list<int>::iterator iter = l.begin();
    shift(iter, m - 1);

    cout << "<";
    while (!l.empty()) {
        cout << *iter;

        l.erase(iter);
        if (!l.empty())
            cout << ", ";

        if (iter != l.begin())
            iter--;

        shift(iter, m);        
    }
    cout << ">\n";
    return 0;
}