#include <string>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
	int answer = 0;
	priority_queue<int> pq;

	int idx = 0;
	for (int i = 0; i < k; i++) {
		if (idx < dates.size() && i == dates[idx]) {
			pq.push(supplies[idx++]);
		}
		if (stock == 0) {
			stock += pq.top();
			pq.pop();
			answer++;
		}
		stock--;
	}
	return answer;
}