#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    string str = to_string(x);
    int n = 0;
    for (char c : str) n += c - '0';
    answer = x % n == 0 ? true : false;
    return answer;
}