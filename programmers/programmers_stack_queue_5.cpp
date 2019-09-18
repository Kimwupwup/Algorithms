#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string arrangement)
{
    int answer = 0;
    int open = 0;
    char prev = '(';

    while (!arrangement.empty())
    {
        char text = arrangement[0];
        arrangement.erase(arrangement.begin());

        if (text == '(')
            open++;
        else if (text == ')')
        {
            if (prev == '(')
            {
                answer += open - 1;
                open--;
            }
            if (prev == ')')
            {
                answer += 1;
                open--;
            }
        }
        prev = text;
    }
    return answer;
}

int main()
{
    string arrangement = "()(((()())(())()))(())";
    cout << solution(arrangement);
}