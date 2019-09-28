#include <vector>
#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int solution(vector<int> budgets, int M)
{
    int answer = 0;
    long long sum = 0;
    sort(budgets.begin(), budgets.end());
    for (int a : budgets)
        sum += a;
    if (sum < M) return budgets.back();
    
    int left = 0;
    int right = budgets.back();
    int mid = (left + right) / 2;
    int prev_mid = mid;

    while (true) {
        sum = 0;
        for (int i = 0; i < budgets.size(); i++) {
            if (budgets[i] <= mid) sum += budgets[i];
            else {
                sum += (budgets.size() - i) * mid;
                break;
            }
        }

        if (sum < M) {
            left = mid;
        } else if (sum > M) {
            right = mid;            
        } else if (sum == M) {
            break;
        }        

        mid = (left + right) / 2;

        if (prev_mid == mid) break;
        prev_mid = mid;
    }

    answer = mid;
    return answer;
}

int main() {
    vector<int> bud = {120, 110, 140, 150};
    cout << "answer : " << solution(bud, 485) << endl;
}