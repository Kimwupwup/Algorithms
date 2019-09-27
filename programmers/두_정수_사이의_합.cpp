#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;
    int temp;
    if (a > b) {
        temp = b;
        b = a;
        a = temp;
    }
    for (int i = a; i <= b; i++) {
        answer += i;
    }
    return answer;
}