/**
 * 백준 2864번 - 5와 6의 차이
 * 5번과 6번을 헷갈려함
 * */

#include <iostream>
#include <string>

using namespace std;

string a, b;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> a >> b;

    int maxi, mini;

    for (char &tmp : a)
        if (tmp == '5')
            tmp = '6';
    for (char &tmp : b)
        if (tmp == '5')
            tmp = '6';
    maxi = stoi(a) + stoi(b);

    for (char &tmp : a)
        if (tmp == '6')
            tmp = '5';
    for (char &tmp : b)
        if (tmp == '6')
            tmp = '5';
    mini = stoi(a) + stoi(b);
    cout << mini << " " << maxi << "\n";
}