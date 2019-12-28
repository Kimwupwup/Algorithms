/**
 * http://codeforces.com/contest/1272
 * Codefores round #605 20191212
 * B. Snow Walking Robot
 * 
 * 최근에 너는 snow walking robot을 구매했고 고놈의 집도 삿지.
 * 무한한 매트릭스의 (0, 0)에 집이 있다는 거임
 * 
 * L R U D 의 string으로 움직인다는 거 같아.
 * L: x - 1, y
 * R: x + 1, y
 * U: x, y + 1
 * D: x, y - 1
 * 
 * (0, 0)에서 시작하는데, 방문했던 그리드는 다시 방문하면 안된다는 말같아.
 * 즉 UUDDD 는 (0, 1)이 중복되니까 안된다는 말.
 * 하지만! (0, 0)은 두번 최대 두번 방문해야해(시작과 끝)
 * 
 * 입력을 줄때, 무조건 유효하게 주지 않는다는 말이야.
 * 
 * 시퀀스가 주어졌을 때, 최소한의 명령 제거로 유효한 시퀀스가 되도록
 * 재배열 하라는 것.
 * 
 * TODO:
 * 하고 안하고 탐색?
 * */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string ret;
vector<int> v;

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        v.clear();
        v.resize(4);
        string str;
        cin >> str;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'L')
                v[0]++;
            else if (str[i] == 'R')
                v[1]++;
            else if (str[i] == 'U')
                v[2]++;
            else if (str[i] == 'D')
                v[3]++;
        }

        
        int width = min(v[0], v[1]);
        int height = min(v[2], v[3]);

        if (v[0] == 0 || v[1] == 0 || v[2] == 0 || v[3] == 0) {
            if (v[0] == 0 || v[1] == 0) {
                if (v[2] == 0 || v[3] == 0) {
                    cout << 0 << "\n";
                    cout << "\n";
                }  
                else {
                    cout << 2 << "\n";
                    cout << "UD" << "\n";
                }
            }
            else if (v[2] == 0 || v[3] == 0) {
                if (v[0] == 0 || v[1] == 0) {
                    cout << 0 << "\n";
                    cout << "\n";
                }                
                else {
                    cout << 2 << "\n";
                    cout << "RL" << "\n";
                }
            }
        }
        else {
            cout << width + width + height + height << "\n";
            for (int i = 0; i < width; i++) {
                cout << "L";
            }
            for (int i = 0; i < height; i++) {
                cout << "U";
            }
            for (int i = 0; i < width; i++) {
                cout << "R";
            }
            for (int i = 0; i < height; i++) {
                cout << "D";
            }
            cout << "\n";
        }
    }   
}