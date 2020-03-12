/**
 * 백준 5397번 - 키로거
 * 
 * TODO:
 * 구현, 시뮬레이션, 스택
 * 스택 2개를 사용하여 구현할 수 있습니다. (왼쪽, 오른쪽 스택)
 * (빈 스택 예외 처리)
 * '<' : 왼쪽 스택에서 오른쪽 스택으로 이동시킵니다. 
 * '>' : 오른쪽 스택에서 왼쪽 스택으로 이동시킵니다.
 * '-' : 왼쪽 스택에서 제거합니다.
 * 문자 입력 : 왼쪽 스택에 추가합니다.
 * */
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    
    while (n--) {
        string str;
        cin >> str;

        vector<char> left;
        vector<char> right;

        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '<') {
                if (!left.empty()) {
                    char temp = left.back();
                    left.pop_back();
                    right.push_back(temp);
                }
            }
            else if (str[i] == '>') {
                if (!right.empty()) {
                    char temp = right.back();
                    right.pop_back();
                    left.push_back(temp);
                }
            }
            else if (str[i] == '-') {
                if (!left.empty()) {
                    left.pop_back();
                }
            }
            else {
                left.push_back(str[i]);
            }
        }
        int size = right.size();
        for (int i = 0; i < size; i++) {
            char temp = right.back();
            right.pop_back();
            left.push_back(temp);
        }
        for (char a : left)
            cout << a;
        cout << "\n";
    }

    return 0;
}