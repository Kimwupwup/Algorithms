#include <string>
#include <vector>
#include <iostream>
#include <memory.h>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int idx = 0;
    int matrix['Z' - 'A' + 1];

    memset(matrix, 0, sizeof(matrix));

    for (char c : skill) {
        matrix[c - 'A'] = ++idx;
    }

    for (string str : skill_trees) {
        bool isFound = false;
        idx = 0;

        for (char c : str) {
            if (matrix[c - 'A'] == 0) continue;
            if (matrix[c - 'A'] != 0)
                if (matrix[c - 'A'] != ++idx) {
                    isFound = true;
                    break;
                }
        }
        if (isFound == false) {
            answer++;
        }
    }
    return answer;
}

int main() {
    string skill = "CBD";
    vector<string> skill_trees = {"BACDE", "CBADF", "AECB", "BDA"};

    cout << solution(skill, skill_trees) << endl;
}