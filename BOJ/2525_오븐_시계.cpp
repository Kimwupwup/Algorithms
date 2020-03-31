/**
 * 백준 2525번 - 오븐 시계
 * 
 * */
#include <iostream>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int hh, mm, cost;
    cin >> hh >> mm >> cost;

    mm += cost;

    hh += (mm / 60);
    mm %= 60;
    hh %= 24;
    cout << hh << " " << mm << "\n";
    return 0;
}