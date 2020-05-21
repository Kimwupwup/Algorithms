/**
 * 백준 1264번 - 모음의 개수
 * 
 * */
#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    while (true) {
        string temp;
        getline(cin, temp);

        if (temp == "#") break;

        int ret = 0;
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i] == 'a' || temp[i] == 'e' || temp[i] == 'i' || temp[i] == 'o' || temp[i] == 'u') ret++;
            if (temp[i] == 'A' || temp[i] == 'E' || temp[i] == 'I' || temp[i] == 'O' || temp[i] == 'U') ret++;
        } 
        cout << ret << "\n";
    }
    return 0;
}