#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int k)
{
    int num1 = 1;
    for (int i = 1; i <= n; i++)
        num1 *= i;
    int num2 = 1;
    for (int i = 1; i <= k; i++)
        num2 *= i;
    int num3 = 1;
    for (int i = 1; i <= n - k; i++)
        num3 *= i;

    return ((num1) / (num2 * num3));
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << solution(n, k) << endl;
    return 0;
}