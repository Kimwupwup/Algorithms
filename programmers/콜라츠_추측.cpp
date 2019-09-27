#include <string>
#include <vector>

using namespace std;

int solution(int num) {

    int cnt = 0;
    for (int i = 0; i < 501; i++) {
        if (num == 1) return cnt;
        if (i == 500) return -1;
        if (num % 2 == 0) {
            num /= 2;
        }
        else if (num % 2 == 1) {
            num *= 3;
            num += 1;
        }
        cnt++;
    }
}