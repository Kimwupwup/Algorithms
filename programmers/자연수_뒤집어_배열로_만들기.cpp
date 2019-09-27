#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(long long n) {
    vector<int> answer;
    string str = to_string(n);
    reverse(str.begin(), str.end());
    for (char c : str)
        answer.push_back(c - '0');
    return answer;
}