#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<memory.h>

using namespace std;

char matrix[101][101];
bool visited[101][101];

vector<pair<int, int>> dir = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

int main() {
	int n;
	int result;
	char current;
	queue<pair<int, int>> q;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> matrix[i][j];
		}
	}

	result = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				result++;
				current = matrix[i][j];
				
				visited[i][j] = true;
				q.push({ i, j });

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nextY = y + dir[k].first;
						int nextX = x + dir[k].second;

						if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n) {
							if (!visited[nextY][nextX] && matrix[nextY][nextX] == current) {
								visited[nextY][nextX] = true;
								q.push({ nextY, nextX });
							}
						}
					}
				}
			}
		}
	}
	cout << result << " ";
	result = 0;
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				result++;
				current = matrix[i][j];

				visited[i][j] = true;
				q.push({ i, j });

				while (!q.empty()) {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					for (int k = 0; k < 4; k++) {
						int nextY = y + dir[k].first;
						int nextX = x + dir[k].second;

						if (nextY >= 0 && nextY < n && nextX >= 0 && nextX < n) {
							if (!visited[nextY][nextX] && matrix[nextY][nextX] == current) {
								visited[nextY][nextX] = true;
								q.push({ nextY, nextX });
							}
							else if (!visited[nextY][nextX] && matrix[nextY][nextX] == 'R' && current == 'G') {
								visited[nextY][nextX] = true;
								q.push({ nextY, nextX });
							}
							else if (!visited[nextY][nextX] && matrix[nextY][nextX] == 'G' && current == 'R') {
								visited[nextY][nextX] = true;
								q.push({ nextY, nextX });
							}
						}
					}
				}
			}
		}
	}

	cout << result;
	return 0;
}