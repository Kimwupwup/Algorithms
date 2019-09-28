#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    sort(arr.begin(), arr.end(), greater<int>());

    int temp = arr[0];
    int sum = 0;
    while (true) {
        bool isNot = false;
        sum += temp;
        for (int i = 1; i < arr.size(); i++) {
            if (sum % arr[i] != 0) {
                isNot = true;
                break;
            }
        }
        if (isNot) continue;
        else break;
    }
    answer = sum;
    return answer;
}