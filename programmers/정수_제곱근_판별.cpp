#include <string>
#include <vector>
#include <math.h>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    int idx = 0;
    for (int i = 1; pow(i, 2) <= n; i++) {
        if (pow(i, 2) == n) idx = i;
    }
    if (idx == 0) answer = -1;
    else answer = pow(idx + 1, 2);
    return answer;
}