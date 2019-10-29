#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 301;
int n, m;
int cnt = 0;

int solution()
{
    cnt += n - 1;
    cnt += n * (m - 1);
    return cnt;
}

int main()
{
    cin >> n >> m;
    cout << solution() << endl;
    return 0;
}