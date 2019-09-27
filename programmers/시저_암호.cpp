#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    int size = 'z' - 'a' + 1;

    for (char c : s) {
        if (c >= 'a' && c <= 'z') {
            c = c + n > 'z' ? c + n - size : c + n;
        } else if (c >= 'A' && c <= 'Z') {
            c = c + n > 'Z' ? c + n - size : c + n;
        }
        answer += c;
    }
    return answer;
}