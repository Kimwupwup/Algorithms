#include <iostream>
using namespace std;
long long matrix[91];
int main()
{
    int n;
    cin >> n;
    matrix[0] = 0;
    matrix[1] = 1;

    for (int i = 2; i <= n; i++)
    {
        matrix[i] = matrix[i - 1] + matrix[i - 2];
    }
    cout << matrix[n] << endl;
    return 0;
}