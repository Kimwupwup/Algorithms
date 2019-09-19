#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(string number, int k)
{
    string answer = "";
    vector<char> stack;

    for (int i = 0; i < number.size(); i++) {
        int stack_size = stack.size();
        for (int j = stack_size - 1; j > -1; j--) {
            if (number[i] > stack[j] && k > 0) {
                stack.pop_back();
                k--;
            }
            else break;
        }
        if (stack.size() < number.size() - k)
            stack.push_back(number[i]);
    }
    for (int i = 0; i < stack.size(); i++) {
        answer += stack[i];
    }
    return answer;
}

int main()
{
    vector<string> number = {"1924", "1231234", "4177252841", "321"};
    vector<int> k = {2, 3, 4, 1};

    for (int i = 0; i < number.size(); i++)
    {
        cout << solution(number[i], k[i]) << endl;
    }
}