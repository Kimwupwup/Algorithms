#include <string>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> baseball) {
    int answer = 0;
    vector<pair<pair<int, int>, string>> v;
    cout << "[call]" << endl;   
    for (vector<int> quest : baseball) {
        int div = 100;
        string call_to_string = "";
        int call = quest[0];
        int strike = quest[1];
        int ball = quest[2];
        for (int i = 0; i < 3; i++) {
            call_to_string += (call / div) + '0';
            call %= div;
            div /= 10;
        }
        v.push_back({{strike, ball}, call_to_string});

        cout << call_to_string << endl;
    }
    cout << endl;

    string temp = "000";
    for (int i = 1; i < 10; i++) {
        temp[0] = i + '0';
        for (int j = 1; j < 10; j++) {
            if (i == j) continue;
            temp[1] = j + '0';
            for (int l = 1; l < 10; l++) {
                if (i == l || j == l) continue;
                temp[2] = l + '0';
                bool isFound = false;
                for (int k = 0; k < v.size(); k++) {
                    string call = v[k].second;
                    int strike = v[k].first.first;
                    int ball = v[k].first.second;
                    int t_strike = 0;
                    int t_ball = 0;
                    
                    for (int h = 0; h < 3; h++) {
                        for (int g = 0; g < 3; g++) {
                            if (h == g && temp[h] == call[g]) t_strike++;
                            else if (h != g && temp[h] == call[g]) t_ball++;
                        }
                    }
                    if (strike == t_strike && ball == t_ball) {
                        isFound = true;
                        continue;
                    } else {
                        isFound = false;
                        break;
                    }
                }
                if (isFound) {
                    cout << temp << endl;
                    answer++;
                }
            }
        }
    }

    return answer;
}

int main() {
    vector<vector<int>> baseball = {{123, 1, 1}, {356, 1, 0}, {327, 2, 0}, {489, 0, 1}};

    int ans = solution(baseball);
    cout << ans << endl;
}