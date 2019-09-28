#include <string>
#include <vector>

using namespace std;

long long solution(int N) {
    long long answer = 0;
    vector<long long> cache(N + 1);

    if (N == 1) {
        return 1;
    }
    else if (N == 2) {
        return 2;
    }

    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= N; i++) {
        cache[i] = cache[i - 2] + cache[i - 1];
    }

    answer = cache[N] * 2 + cache[N - 1] * 2;
    return answer;
}