/**
 * 백준 13458번 - 시험 감독
 * 
 * N개 시험장에 응시자 A명
 * 총감독관은 1명, 부감독은 여러명
 * B명 가능, C명 가능
 * 감독관의 최소를 구하라...
 * 
 * TODO:
 * 브루트포스
 * */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
vector<int> v;
int b, c;
long long ret = 0;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }
    cin >> b >> c;

    for (int i = 0; i < n; i++) {
        int temp = v[i];
        temp -= b;
        ret++;
        if (temp <= 0) {
            continue;
        }
        ret += temp / c;
        ret += (temp % c) ? 1 : 0;
        
    }
    cout << ret << "\n";
    return 0;
}