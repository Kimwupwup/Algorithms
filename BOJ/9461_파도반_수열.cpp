#include <iostream>
using namespace std;
long long matrix[101];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    matrix[0] = 0;
    matrix[1] = 1;
    matrix[2] = 1;
    matrix[3] = 1;
    matrix[4] = 2;
    matrix[5] = 2;

    for (int i = 6; i < 101; i++)
    {
        matrix[i] = matrix[i - 1] + matrix[i - 5];
    }

    int t;
    cin >> t;
    int n;
    for (int i = 0; i < t; i++)
    {
        cin >> n;
        cout << matrix[n] << endl;
    }
    return 0;
}