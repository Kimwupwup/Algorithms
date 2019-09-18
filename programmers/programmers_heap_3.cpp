#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
struct cmp {
	bool operator()(vector<int> a, vector<int> b) {
		return a[1] > b[1];
	}
};

bool cmpp(vector<int> a, vector<int> b) {
	return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	
	priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
	int sum = 0;
	int current = 0;
	int idx = 0;
	int stock = 0;
	int prev = 0;

	sort(jobs.begin(), jobs.end(), cmpp);

	while (true) {
		while (idx != jobs.size()) {
			if (jobs[idx][0] == current) {
				pq.push(jobs[idx++]);
			}
			else break;
		}

		if (stock <= 0 && !pq.empty()) {
			stock = pq.top()[1];
			sum += pq.top()[1];
			pq.pop();
		}
		sum += pq.size();
		stock--;
		current++;

		if (pq.empty() && idx == jobs.size() && stock == 0) break;
	}
	answer = sum / jobs.size();
	return answer;
}

int main() {
	vector<vector<int>> jobs = { {0, 3}, {4, 9}, {3, 6} };
	cout << solution(jobs) << endl;
}