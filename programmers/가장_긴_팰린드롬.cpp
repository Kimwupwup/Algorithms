#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(string s)
{
    int answer=0;
    string quest = "";
    vector<int> v;

    for (int i = 0; i < s.size(); i++) {
        quest += "#";
        quest += s[i];
    }
    quest += "#";
    v.resize(quest.size() + 1, 0);
    // r은 값, p는 중심점
    int r = 0, p = 0;
    for (int i = 0; i < quest.size(); i++) {
        if (i <= r) {
            v[i] = min(v[2 * p - i], r - i);
        } else {
            v[i] = 0;
        }

        while (i - v[i] - 1 >= 0 && i + v[i] + 1 < quest.size() && quest[i - v[i] - 1] == quest[i + v[i] + 1]) {
            v[i]++;
        }

        if (r < i + v[i]) {
            r = i + v[i];
            p = i;
        }
    }
    for (int i = 0; i < quest.size(); i++) {
        answer = max(answer, v[i]);
    }
    return answer;
}

int main() {
    cout << solution("abcdcbsa");
}