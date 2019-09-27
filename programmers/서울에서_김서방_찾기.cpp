#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    int idx;
    for (int i = 0; i < seoul.size(); i++) {
        if ("Kim" == seoul[i]) idx = i;
    }
    answer += "김서방은 ";
    answer += to_string(idx);
    answer += "에 있다.";
    cout << answer << endl;
    return answer;
}