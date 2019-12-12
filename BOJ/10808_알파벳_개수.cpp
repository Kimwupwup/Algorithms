/**
 * 백준 10808번 - 알파벳 개수
 * hash(map)
 * 배열로도 가능
 * */

#include <iostream>
#include <string>

using namespace std;

int matrix[26];

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string str;
    cin >> str;
    for (char a : str) {
        matrix[a - 'a']++;
    }
    for (int i = 0; i < 26; i++)
        cout << matrix[i] << " ";
    return 0;
}
