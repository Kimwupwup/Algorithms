#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	vector<pair<int, int>> counter;
	vector<vector<int>> number = { { 1, 2, 3, 4, 5 }, { 2, 1, 2, 3, 2, 4, 2, 5 }, { 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 } };

	for (int i = 0; i < 3; i++) {
		int idx = 0;
		int cnt = 0;
		for (int temp : answers) {
			if (temp == number[i][idx]) {
				cnt++;
			}
			idx++;
			if (idx == number[i].size()) idx = 0;
		}
		counter.push_back({ cnt, i + 1 });
	}
	sort(counter.begin(), counter.end(), greater<pair<int, int>>());

	int idx;
	int maxi = counter[0].first;
	for (int i = 0; i < 3; i++) {
		if (maxi == counter[i].first) {
			answer.push_back(counter[i].second);
		}
	}
	sort(answer.begin(), answer.end());
	return answer;
}

int main() {
	vector<vector<int>> answers = { {1, 2, 3, 4, 5}, {1, 3, 2, 4, 2} };
	for (vector<int> temp : answers) {
		vector<int> a = solution(temp);
		for (int ans : a)
			cout << ans << endl;
	}
		
	return 0;
}