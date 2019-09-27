#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> arr) {
    sort(arr.begin(), arr.end(), greater<int>());

    int product = 1;
    while (true) {
        int cnt = 0;
        int next = arr[0] * product++;

        for (int i = 1; i < arr.size(); i++) {
            if (next % arr[i] == 0) {
                cnt++;
            }
        }
        if (cnt == arr.size() - 1) return next;
    
    }
}