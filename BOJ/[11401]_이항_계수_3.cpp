/**
 * 백준 11401번 - 이항 계수 3
 * 
 * TODO:
 * 수학, 페르마의 소정리
 * 이항 계수(nCk): n! / k!(n - k)!
 * nCk = (n-1)Ck + (n-1)C(k-1)
 * 페르마의 소정리: p(mod) 가 소수이고 a 가 p 의 배수가 아니면,
 * a^(p-1) = 1(mod p) 이다.
 * 즉, a^(p-1) 을 p로 나눈 나머지는 1 이다.
 * 
 * A*A^(p - 2) = 1(mod p)
 * A^(p - 2) = A^(-1)(mod p)
 * */
#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 4000001;
const int MOD = 1000000007;
long long fac[MAX], inv[MAX];
int n, k;

long long my_pow(long long a, long long b) {
    long long ret = 1;
    
    while (b > 0) {
        if (b % 2) {
            ret *= a;
            ret %= MOD;
        }
        a *= a;
        a %= MOD;
        b /= 2;
    }
    return ret;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    fac[1] = 1;
    for (int i = 2; i < MAX; i++) {
        fac[i] = (fac[i - 1] * i) % MOD;
    }
    inv[MAX - 1] = my_pow(fac[MAX - 1], MOD - 2);
    for (int i = MAX - 2; i > 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % MOD;
    }

    cin >> n >> k;
    if (n == k || !k) {
        cout << 1 << "\n";
        return 0;
    }
    long long ret = (fac[n] * inv[n - k]) % MOD;
    ret = (ret * inv[k]) % MOD;
    cout << ret << "\n";

    return 0;
}