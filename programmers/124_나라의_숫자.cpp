#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(int n) {
    vector<int> v = {4, 1, 2};
    vector<int> saver;
    string answer = "";

    while (n > 0) {
        saver.push_back(n % 3);
        n /= 3;
        if (saver[saver.size() - 1] == 0) n -= 1;
    }
    reverse(saver.begin(), saver.end());

    for (int i = 0; i < saver.size(); i++) {
        answer += v[saver[i]] + '0';
    }
    return answer;
}