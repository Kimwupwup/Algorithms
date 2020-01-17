/**
 * 백준 15596번 - 정수 N개의 합
 * 
 * */
#include <vector>
#include <iostream>

long sum(std::vector<int> &a) {
    long ret = 0;
    for (int temp : a) 
        ret += temp;
    return ret;    
}

int main() {
    std::vector<int> a = {1, 2, 3, 4, 5};
    std::cout << sum(a);
    return 0;
}