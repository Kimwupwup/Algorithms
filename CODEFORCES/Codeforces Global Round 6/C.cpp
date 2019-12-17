/**

 * Codeforces Global Round 6
 * C. Diverse Matrix
 * 
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
    if (a % b == 0)
        return b;
    return GCD(b, a % b);
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    
    return 0;
}