#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> weight) {
    int answer = 0;
    sort(weight.begin(), weight.end());

    int num = weight.size();
    int idx = 0;
    int result = 0;
    int temp = 1;

	while (true) {

		if (result < temp) {
			if (idx > num - 1) {
				idx = num - 1;
			}
			else {
				result += weight[idx];
				idx++;
			}
		}

		if (idx == num - 1 && temp > result) {
			
			return temp;
		}
		if (result - temp >= temp) {
			
			return temp;
		}
		else {
			temp = result + 1;
		}
	}
	return temp;
}

int main() {
    vector<int> weights = {
        3, 1, 6, 2, 7, 30, 1
    };
    cout << solution(weights);
}