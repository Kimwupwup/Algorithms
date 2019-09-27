#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pcnt = 0, ycnt = 0;
    for (char c : s) {
        if (tolower(c) == 'p') pcnt++;
        if (tolower(c) == 'y') ycnt++;
    }
    if (pcnt == ycnt) answer = true;
    else answer = false;
    return answer;
}