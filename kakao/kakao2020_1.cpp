/**
 * KAKAO Blind Test 2020
 * 1번 - 문자열 압축
 * */
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

int count(string s, int unit_size) {
    vector<string> v;
    string ret = "";

    for (int i = 0; i < s.size(); i += unit_size) {
        v.push_back(s.substr(i, unit_size));
    }

    for (int i = 0; i < v.size(); i++) {
        int j;
        for (j = i + 1; j < v.size(); j++) {
            if (v[i] != v[j])
                break;
        }
        if (j == i + 1)
            ret += v[i];
        else {
            ret += to_string(j - i);
            ret += v[i];
            i = j - 1;   
        }
    }
    return ret.size();
}

int solution(string s) {
    int answer = s.size();
    int size = s.size();

    for (int i = 1; i <= size / 2; i++) {
        int temp = count(s, i);
        answer = min(answer, temp);
    }

    return answer;
}


