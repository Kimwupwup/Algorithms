#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string str = to_string(n);
    sort(str.begin(), str.end(), greater<char>());
    answer = stoll(str);
    return answer;
}

int main() {
    cout << solution(8000000000);

}