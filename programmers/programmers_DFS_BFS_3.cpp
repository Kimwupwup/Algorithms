#include <string>
#include <vector>
#include <iostream>
#include <memory.h>
#include <algorithm>

using namespace std;

bool visited[50];
vector<int> anss;

bool check(string a, string b) {
    int cnt = 0;
    int size = a.size();

    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) cnt++;
    }
    if (cnt != 1) return false;
    return true;
}

void DFS(vector<string> words, int idx, int cnt, string target) {
    if (words[idx] == target) {
        anss.push_back(cnt);
    }

    for (int i = 0; i < words.size(); i++) {
        if (!visited[i] && check(words[idx], words[i])) {
            visited[i] = true;
            DFS(words, i, cnt + 1, target);
            visited[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    anss.clear();

    memset(visited, false, sizeof(visited));
    for (int i = 0; i < words.size(); i++) {
        if (!visited[i] && check(begin, words[i])) {
            visited[i] = true;
            DFS(words, i, 1, target);
            visited[i] = false;
        }
    }

    sort(anss.begin(), anss.end(), less<int>());
    if (anss.empty()) answer = 0;
    else answer = anss[0];
    return answer;
}

int main() {
    vector<vector<string>> wordss = {
        {"hot", "dot", "dog", "lot", "log", "cog"},
        {"hot", "dot", "dog", "lot", "log"}
    };

    for (vector<string> words : wordss) {
        cout << solution("hit", "cog", words) << endl;
    }
}