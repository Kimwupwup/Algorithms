#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end(), greater<int>());

    int temp = arr[0];

    while (true) {
        bool isNot = false;
        temp += temp;
        for (int i = 1; i < arr.size(); i++) {
            if (temp % arr[i] != 0) {
                isNot = true;
                break;
            }
        }
        if (isNot) continue;
        else break;
    }
    answer = temp;
    return answer;
}