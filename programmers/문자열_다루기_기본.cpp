#include <string>
#include <vector>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    for (char c : s)
    {
        if (c >= 'a' && c <= 'z') {
            answer = false;
            break;
        }
    }
    if (s.size() != 4 && s.size() != 6) answer = false;
    return answer;
}