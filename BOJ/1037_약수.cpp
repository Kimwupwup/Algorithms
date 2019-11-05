#include <iostream>
#include <algorithm>
using namespace std;
int n;
int matrix[51];
int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> matrix[i];
    sort(matrix, matrix + n);
    cout << (matrix[0] * matrix[n - 1]) << endl;
    return 0;
}