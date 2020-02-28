/**
 * 백준 16637번 - 괄호 추가하기
 * 
 * TODO:
 * 
 * */
#include <iostream>
#include <vector>
#include <string>
#include <limits.h>

using namespace std;

const int MAX = 19;
int n;
string str;
bool visited[MAX];
int ret = 0;

int cal() {
    vector<string> temp;

    int idx = 0;
    
    while (idx < n) {
        if (!visited[idx]) {
            string tmp = "";
            tmp += str[idx];

            temp.push_back(tmp);
            idx++;
        }
        else {
            if (str[idx + 1] == '+') {
                temp.push_back(to_string((str[idx] - '0') + (str[idx + 2] - '0')));
            }
            else if (str[idx + 1] == '-') {
                temp.push_back(to_string((str[idx] - '0') - (str[idx + 2] - '0')));
            }
            else if (str[idx + 1] == '*') {
                temp.push_back(to_string((str[idx] - '0') * (str[idx + 2] - '0')));
            }
            idx += 3;
        }
    }

    int temp_ret = stoi(temp[0]);
    for (int i = 1; i < temp.size(); i++) {
        if (temp[i] == "+") {
            temp_ret += stoi(temp[i + 1]);
        }
        else if (temp[i] == "-") {
            temp_ret -= stoi(temp[i + 1]);
        }
        else if (temp[i] == "*") {
            temp_ret *= stoi(temp[i + 1]);
        }
    }
    
    return temp_ret;
}
void DFS(int idx) {
    ret = max(ret, cal());
    for (int i = idx; i + 2 < n; i += 2) {
        if (!visited[i] && !visited[i + 2]) {
            visited[i] = true;
            visited[i + 2] = true;
            DFS(i + 2);
            visited[i] = false;
            visited[i + 2] = false;
        }
    }
}
int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    cin >> str;
    ret = -INT_MAX;

    DFS(0);

    cout << ret << "\n";
    return 0;
}