#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <memory.h>

using namespace std;

vector<pair<int, int>> dir = { {0, 0}, {1, 0}, {0, 1}, {1, 1} };
bool matrix[31][31];

int solution(int m, int n, vector<string> board) {
	int ret = 0;

	while (true) {
		int clear_cnt = 0;
		memset(matrix, false, sizeof(matrix));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				char temp = board[i][j];
				if (temp == '#') continue;
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int nextY = i + dir[k].first;
					int nextX = j + dir[k].second;
					if (nextY >= m || nextX >= n) continue;
					if (temp == board[nextY][nextX]) cnt++;
				}
				if (cnt == 4) {
					for (int k = 0; k < 4; k++) {
						int nextY = i + dir[k].first;
						int nextX = j + dir[k].second;

						if (matrix[nextY][nextX] == false) {
							matrix[nextY][nextX] = true;
							clear_cnt++;
						}
					}
				}
			}
		}

		if (clear_cnt == 0) return ret;
		else ret += clear_cnt;

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (matrix[i][j] == true) {
					board[i][j] = '#';
				}
			}
		}

		for (int i = n - 1; i > -1; i--) {
			queue<pair<int, int>> q;
			for (int j = m - 1; j > -1; j--) {
				if (!q.empty() && board[j][i] != '#') {
					int y = q.front().first;
					int x = q.front().second;
					q.pop();

					board[y][x] = board[j][i];
					board[j][i] = '#';
				}
				if (board[j][i] == '#') q.push({ j, i });
			}
		}
	}
	
	return ret;
}

int main() {

	vector<pair<int, int>> mn = { {4, 5}, {6, 6} };
	vector<vector<string>> board = { {"CCBDE", "AAADE", "AAABF", "CCBBF"}, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"} };

	for (int i = 0; i < mn.size(); i++) {

		cout << solution(mn[i].first, mn[i].second, board[i]) << endl;
	}

	return 0;
}