#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            answer += ' ';
            cnt = 0;
        }
        else {
            if (cnt % 2 == 0) answer += toupper(s[i]);
            else if (cnt % 2 == 1) answer += tolower(s[i]);
            cnt++;
        }
    }
    return answer;
}