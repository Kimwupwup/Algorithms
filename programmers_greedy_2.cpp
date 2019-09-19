#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.size();
    int temp = 0, turn = n - 1;

    for (int i = 0; i < n; i++) {
        int start = name[i] - 'A';
        int end = 'Z' - name[i] + 1;

        if (start > end) temp += end;
        else temp += start;

        int next = i + 1;
        while (next < n && name[next] == 'A') next++;
        turn = min(turn, i + n - next  + min(i , n-next));
    }
    temp += turn;
    answer = temp;
    
    return answer;
}

int main() {
    vector<string> name = {"JEROEN", "JAN"};
    for (string str : name) {
        cout << solution(str) << endl;
    }
}