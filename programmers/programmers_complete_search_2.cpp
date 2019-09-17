#include <string>
#include <vector>
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

string origin;
bool visited[7];
vector<int> set;

void DFS(int idx, string str) {
    str += origin[idx];
    set.push_back(stoi(str));
    for (int i = 0; i < origin.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            DFS(i, str);
            visited[i] = false;
        }
    }
}
// int stringToInt()
int solution(string numbers) {
    int answer = 0;
    origin = numbers;
    for (int i = 0; i < origin.size(); i++) {
        visited[i] = true;
        DFS(i, "");
        visited[i] = false;
    }

    sort(set.begin(), set.end());

    int s = set[0];
    for (int i = 1; i < set.size(); i++) {
        if (s == set[i]) set[i] = -1;
        else if (s != set[i]) s = set[i];
    }

    for (int temp : set) {
        if (temp == -1) continue;
        cout << temp << endl;
    }
    cout << endl;
    cout << "[answer] : ";

    int cnt = 0;
    int size = 0;
    for (int temp : set) {
        if (temp == 0) cnt++;
        if (temp == 1) cnt++;
        if (temp == -1) continue;
        size++;
        for (int i = 2; i < temp; i++) {
            if (temp % i == 0) {
                cnt++;
                break;
            }
        }
    }
    answer = size - cnt;
    return answer;
}

int main() {
    vector<string> numbers = {"17", "011"};
    for (string quest : numbers) {
        set.clear();
        
        cout << solution(quest) << endl << endl;
    }
}