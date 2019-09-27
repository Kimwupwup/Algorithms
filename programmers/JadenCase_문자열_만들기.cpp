#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    bool isFirst = true;

    transform(s.begin(), s.end(), s.begin(), tolower);
    s[0] = toupper(s[0]);
    for (size_t p = s.find(' '); p != string::npos; p = s.find(' ', p + 1)) {
        s[p + 1] = toupper(s[p + 1]);
    }
    // for (int i = 0; i < s.size(); i++) {
    //     if (isFirst) {
    //         s[i] = toupper(s[i]);
    //         isFirst = false;
    //     }
    //     else
    //         s[i] = tolower(s[i]);
        
    //     if (s[i] == ' ')
    //         isFirst = true;
    // }
    answer = s;
    return answer;
}