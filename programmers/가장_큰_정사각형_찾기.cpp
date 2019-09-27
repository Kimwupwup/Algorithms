#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 1234;
    int height = board.size();
    int width = board[0].size();
    
    int maxi = 0;
    if (height == 1 || width == 1) {
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (board[i][j] == 1) return 1;
            }
        }
    }
    for (int i = 1; i < height; i++) {
        for (int j = 1; j < width; j++) {
            if (board[i][j] == 1) {
                board[i][j] = min(board[i - 1][j], min(board[i][j - 1], board[i - 1][j - 1])) + 1;
            }
        }
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (maxi < board[i][j]) maxi = board[i][j];
        }
    }
    answer = maxi * maxi;
    return answer;
}

int main() {
    vector<vector<int>> v = 
    {{0,1,1,1},{1,1,1,1},{1,1,1,1},{0,0,1,0}};
    solution(v);
}