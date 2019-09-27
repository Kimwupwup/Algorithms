#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> v;

int cal(int num) {
    v.clear();
    int ret = 0;
    while (num != 0) {
        if (num % 2 == 1) ret++;
        num /= 2;
    }
    return ret;
}

int solution(int n) {
    int answer = 0;
    vector<int> v;
    
    int target = cal(n);
    cout << target << endl;
    while (true) {        
        n++;        
        int cur = cal(n);
        if (target == cur) break;
        
    }
    return answer = n;
}

int main() {
    solution(15);
}