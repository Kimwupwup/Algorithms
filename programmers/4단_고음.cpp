// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
#include <math.h>

using namespace std;

int answer = 0;

void DFS(int add, int n) {
    if (pow(3, add / 2) > n) return;
    if (n == 3) {
        if (add == 2) answer++;
    } else if (n > 3) {
        if (add >= 2 && n % 3 == 0) DFS(add - 2, n / 3);
        DFS(add + 1, n - 1);
    }
}

int solution(int n) {
    answer = 0;
    DFS(0, n);
    return answer;
}