#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int size = n / 2 + 1;
    for (int i = 1; i < size; i++) {
        int sum = 0;
        for (int j = i; sum <= n; j++) {
            sum += j;
            if (sum == n) answer++;
        }
    }
    return answer + 1;
}