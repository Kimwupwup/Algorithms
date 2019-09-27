#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int temp = n < m ? n : m;

    for (int i = temp; i > -1; i--) {
        if (n % i == 0 && m % i == 0) {
            answer.push_back(i);
            break;
        }
    }
    
    int up = n > m ? n : m;
    int pro = 1;
    while (true) {
        int t = up * pro;

        if (t % temp == 0) {
            answer.push_back(t);
            break;
        }
        pro++;
    }
    return answer;
}