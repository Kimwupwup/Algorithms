#include <iostream>
#include <math.h>
#include <memory.h>

using namespace std;

int matrix[10001];

int main()
{
    memset(matrix, true, sizeof(matrix));
    int start, finish;
    cin >> start >> finish;

    // Eratosthenes
    matrix[1] = false;
    for (int i = 2; i <= sqrt(finish); i++)
        if (matrix[i])
            for (int j = i * i; j <= finish; j += i)
                matrix[j] = false;

    int sum = 0;
    int min = 0;
    for (int i = start; i <= finish; i++)
    {
        if (min == 0 && matrix[i])
            min = i;
        if (matrix[i])
            sum += i;
    }
    if (sum == 0)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << sum << endl;
    cout << min << endl;
}