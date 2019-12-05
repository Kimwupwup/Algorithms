/**
 * 백준 1086번 - 박성원
 * 
 * TODO:
 * 순열을 조합하여 K로 나눠지는 가, 확인해야 한다.
 * 순열의 조합 중에서 K로 나눠질 확률을 구해야 한다.
 * 순열의 갯수를 구할 수 있어야 한다.
 * 
 * FIXME:
 * 입력할 숫자들의 길이는 50이하이다.
 * 따라서 string으로 입력을 받고 처리해야 한다.
 * 한번에 나머지를 구할 수 없으므로, 각 자리수에 맞도록 K로 나눠 처리해야한다.
 * 또한 숫자들이 바로 이어지는 방식이므로, 뒤에 들어올 숫자에 대한 자리를 만들어야 한다.
 * 이는 이미 들어가 있는 숫자에 (들어갈 숫자의 길이 % K)를 곱하면 들어갈 숫자의 공간을
 * 확보할 수 있다.
 * 
 * DP[i][j] 는 현재 숫자 i, 지금까지 사용된 숫자들 j 가 K로 나눠지는 갯수이다.
 * 비트마스트를 사용한다.
 * */

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int const N_MAX = 16;
int const M_MAX = 52;
int const K_MAX = 101;

int N, K;

string str_numbers[N_MAX];
int pows[M_MAX];
int numbers[N_MAX];
int length_numbers[N_MAX];

long long dp[K_MAX][1 << N_MAX];

long long facto (int a) {
    long long ret = 1;
    for (int i = 1; i <= a; i++)
        ret *= i;
    return ret;
}

long long gcd (long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

long long solution (int current, int visited) {

    // 모두 다 끝났으면, 나머지(current)가 0일 때, 1을 반환한다.
    if (visited == (1 << N) - 1)
        return (current == 0 ? 1 : 0);
    
    long long &ret = dp[current][visited];
    if (ret != -1)
        return ret;
    ret = 0;

    for (int i = 0; i < N; i++) {
        int mask = (1 << i);

        // 방문했던 거라면 패스
        if (visited & mask)
            continue;
        
        // 현재 숫자를 추가하고 다음 수열을 생성하여
        // 현 상태에 갯수를 추가한다.
        ret += solution((current * pows[length_numbers[i]] + numbers[i]) % K, visited + mask);
    }

    return ret;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> str_numbers[i];
    cin >> K;

    /**
     * 각 자리수의 power를 구한다.
     * {32, 500} 이라면, 순열을 만들었을 때 32500일 것이다.
     * 처음으로 32가 추가되고, 500이 추가되야 할때,
     * 500의 length는 3이다. 그럼 number_lengths[1]은 3이 들어있고,
     * pows[number_lengths[1]]에는 1000이 들어있게 된다.
     * 
     * 32 에 pows[number_lengths[1]] = 1000 을 곱하면 32000이 되서, 
     * 500이 들어갈 자리가 만들어진다.
     * 
     * k의 나머지를 넣는 이유는 각 숫자들은 전부 k의 나머지가
     * 들어있기 때문에, 자리수를 곱해줄 때에도 그에 맞게 k의 나머지를
     * 곱해야줘야 하기때문이다.
     * */
    pows[0] = 1;
    for (int i = 1; i <= 50; i++) {
        pows[i] = pows[i - 1] * 10 % K;
    }

    /**
     * 각 자리수에 대해서 k를 나눠주면,
     * 오버플로가 발생하지 않고도, k의 나머지를 구할 수 있다.
     * 보통 사람들이 연산하는 방식과 동일하다.
     * */
    for (int i = 0; i < N; i++) {
        length_numbers[i] = str_numbers[i].length();
        for (int j = 0; j < length_numbers[i]; j++) {
            numbers[i] = ((numbers[i] * 10) + (str_numbers[i][j] - '0')) % K;
        }
    }

    memset(dp, -1, sizeof(dp));
    long long answer = solution(0, 0);
    long long all_set = facto(N);

    if (answer == 0)
        cout << "0/1" << endl;
    else if (answer == all_set)
        cout << "1/1" << endl;
    else {
        // 최대공약수를 통해 기약분수로 만들 수 있다.
        long long div = gcd(answer, all_set);
        long long a = answer / div;
        long long b = all_set / div;
        cout << a << "/" << b << endl;
    }
    return 0;
}