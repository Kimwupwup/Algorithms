/**
 * 백준 7453번 - 합이 0인 네 정수
 * 
 * TODO:
 * 자료구조
 * 총 4개의 값들중 2개 / 2개로 나눠 생각할 수 있다.
 * 먼저 2개의 값들을 더한 값을 모두 저장한다.
 * 그리고 나머지 2개의 값을 전부 더하고, 먼저 더해둔 값들에서 뺄셈이 0이 되는 것들을 찾는다.
 * (4000 * 4000) * 2
 * 하지만 값이 여러개 일 가능성이 있다. 이를 전부 찾는 행위를 반복한다면 TLE 가 발생한다.
 * lower_bound, upper_bound를 사용하여 하계, 상계를 찾아 빼주게 되면 이에 해당하는
 * 갯수를 알 수 있다. (lower_bound, upper_bound 는 이분탐색이라 빠르다.)
 * 
 * unordered_map 은 O(1)의 탐색을 할 것이라 생각하지만, 이는 크기가 커지면 resize 의
 * 시간과 충돌의 시간을 고려하게 되면 생각보다 빠르지 않은 방식이다.
 * multiset 을 사용하게 되었을 때, TLE 가 발생하였다. 이 방식도 위와 같은 이유로
 * TLE 가 발생했다고 생각한다.
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<long long> v[5];
int n;
long long ret = 0;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 4; j++) {
            int temp;
            cin >> temp;
            v[j].push_back(temp);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            v[4].push_back(v[0][i] + v[1][j]);
        }
    }

    sort(v[4].begin(), v[4].end());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long temp = v[2][i] + v[3][j];
            long long left = lower_bound(v[4].begin(), v[4].end(), -temp) - v[4].begin();
            long long right = upper_bound(v[4].begin(), v[4].end(), -temp) - v[4].begin();

            if (-temp == v[4][left])
                ret += (right - left);
        }
    }
    cout << ret << "\n";
    return 0;
}