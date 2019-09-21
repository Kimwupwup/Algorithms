#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int solution(int n, vector<vector<int>> results)
{
    int answer = 0;
    int infi = 987654321;

    int matrix[101][101];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            matrix[i][j] = i == j ? 0 : infi;
        }
    }

    for (int i = 0; i < results.size(); i++) {
        int y = results[i][0];
        int x = results[i][1];
        matrix[y][x] = 1;
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
            }
        }
    }

    vector<int> unknown;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (matrix[i][j] == infi && matrix[j][i] == infi) {
                unknown.push_back(i);
                break;
            }
        }
    }
    answer = n - unknown.size();
    return answer;
}

int main()
{
    vector<vector<int>> results =
        {{4, 3}, {2, 5}, {4, 2}, {3, 2}, {1, 2}};

    cout << solution(5, results);    
}