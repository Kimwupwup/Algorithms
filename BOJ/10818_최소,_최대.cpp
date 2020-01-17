/**
 * 백준 10818번 - 최소, 최대
 * 
 * */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a;
    vector<int> v;
    cin >> a;
    v.resize(a);
    for (int i = 0; i < a; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    cout << v[0] << " " << v[v.size() - 1] << "\n";
}