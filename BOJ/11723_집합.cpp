/**
 * 백준 11723번 - 집합
 * 
 * set을 사용한다. (시간 초과)
 * 배열(cache)을 사용한다. (통과)
 * 
 * 이유: 
 * set는 이진 탐색 트리의 형태를 가지고 있다.
 * 따라서 탐색(find())을 하게 되면, 트리 높이 만큼의 탐색 시간이 소요하게 된다.
 * 이에 따라 시간 초과가 발생하는 것으로 보인다.
 * 
 * 하지만 배열을 사용하게 되면 이러한 탐색 시간이 소요되지 않는다. O(1)의 탐색 시간이 소요된다.
 * 그렇기에 시간 초과가 발생하지 않는다.
 * 
 * 비트마스크 문제였다.
 * */

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool cache[21];

int main() {

    cin.tie(NULL);
    ios::sync_with_stdio(false);
    memset(cache, false, sizeof(cache));

    int n;
    cin >> n;

    while (n--) {
        string str;
        int num;
        
        cin >> str;
        if (str == "add") {
            cin >> num;
            if (!cache[num])
                cache[num] = true;

        } else if (str == "remove") {
            cin >> num;
            if (cache[num])
                cache[num] = false;

        } else if (str == "check") {
            cin >> num;
            cout << (cache[num] ? 1 : 0) << "\n";
 
        } else if (str == "toggle") {
            cin >> num;
            cache[num] = (cache[num] ? false : true);

        } else if (str == "all") {
            memset(cache, true, sizeof(cache));

        } else if (str == "empty") {
            memset(cache, false, sizeof(cache));

        }
    }
    return 0;
}