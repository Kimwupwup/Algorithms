/**
 * 백준 1475번 - 방번호
 * 
 * */

#include <iostream>
#include <string>

using namespace std;

int numbers[10];

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        numbers[str[i] - '0']++;
        if (str[i] - '0' == 6)
            numbers[9]++;
        else if (str[i] = '0' == 9)
            numbers[6]++;
    }

    int max = 0;
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) {
            int temp;
            if (numbers[i] % 2 == 1) {
                temp = numbers[i] / 2 + 1;
            } else {
                temp = numbers[i] / 2;
            }
            if (max < temp)
                max = temp;
        }
            
        else {
            if (max < numbers[i])
                max = numbers[i];
        }
    }
    cout << max << endl;
    return 0;
}