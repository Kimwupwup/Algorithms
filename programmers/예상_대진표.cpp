#include <iostream>

using namespace std;

int solution(int n, int a, int b)
{
    int answer = 3;
    

    for (int i = 0; a != 0 && b != 0; i++) {
        if (a / 2 + a % 2 == b / 2 + b % 2) {
            answer = i + 1;
            break;
        }
        else {
            a = a / 2 + a % 2;
            b = b / 2 + b % 2;
        }
    }
    
    return answer;
}