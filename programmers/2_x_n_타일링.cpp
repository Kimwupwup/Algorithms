#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<long long> cache(n + 1);

    if (n == 1) return 1;
    else if (n == 2) return 2;

    cache[0] = 0;
    cache[1] = 1;
    cache[2] = 2;

    for (int i = 3; i <= n; i++) {
        cache[i] = (cache[i - 2] + cache[i - 1]) % 1000000007;
    }

    answer = (cache[n] % 1000000007); 
    return answer;
}