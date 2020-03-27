/**
 * 백준 1076번 - 저항
 * 
 * */
#include <iostream>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    map<string, int> m;
    m["black"] = 0;
    m["brown"] = 1;
    m["red"] = 2;
    m["orange"] = 3;
    m["yellow"] = 4;
    m["green"] = 5;
    m["blue"] = 6;
    m["violet"] = 7;
    m["grey"] = 8;
    m["white"] = 9;

    string a, b, c;
    cin >> a >> b >> c;

    long long ret = 10;
    ret *= m[a];
    ret += m[b];
    ret *= pow(10, m[c]);

    cout << ret << "\n";

    return 0;
}