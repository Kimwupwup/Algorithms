#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<long long> fibo_cache;

int solution(int n) {
    int answer = 0;
    fibo_cache.resize(n + 1);

    fibo_cache[0] = 0;
    fibo_cache[1] = 1;

    for (int i = 2; i <= n; i++) {
        fibo_cache[i] = (fibo_cache[i - 2] + fibo_cache[i - 1]) % 1234567;
    }
    answer = fibo_cache[n] % 1234567;
    return answer;
}

int main() {
    cout << solution(100000);
}