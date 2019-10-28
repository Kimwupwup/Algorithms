#include <iostream>
#include <algorithm>
using namespace std;
int matrix[1000001];
int main()
{
    int n;
    cin >> n;
    matrix[1] = 0;

    for (int i = 2; i <= n; i++)
    {
        matrix[i] = matrix[i - 1] + 1;
        if (i % 2 == 0)
            matrix[i] = min(matrix[i], matrix[i / 2] + 1);
        if (i % 3 == 0)
            matrix[i] = min(matrix[i], matrix[i / 3] + 1);
    }
    cout << matrix[n] << endl;
    return 0;
}