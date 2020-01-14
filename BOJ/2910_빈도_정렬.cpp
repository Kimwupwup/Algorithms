/**
 * 백준 2910번 - 빈도 정렬
 * 
 * */
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1001;

pair<int, long long> p[MAX];
pair<int, long long> ret[MAX];

long long n, c;

bool cmp(const pair<int, long long> &a, const pair<int, long long> &b) {
    return a.first > b.first;
}

void bubble_sort(pair<int, long long> temp[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (temp[j].first < temp[j + 1].first) {
                pair<int, long long> t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> p[i].second;        
        for (int j = 0; j <= i; j++) {
            if (p[j].second == p[i].second) {
                p[j].first++;
                break;
            }
        }
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
        if (p[i].first != 0) {
            ret[j] = p[i];
            j++;
        }
    }
    
    bubble_sort(ret, j);

    for (int i = 0; i < j; i++) {
        while (ret[i].first) {
            cout << ret[i].second << " ";
            ret[i].first--;
        }
    }
    cout << "\n";

    return 0;
}