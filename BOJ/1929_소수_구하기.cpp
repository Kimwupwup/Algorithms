#include <iostream>
#include <memory.h>
#include <math.h>

using namespace std;

bool matrix[1000001];

int main()
{
    memset(matrix, true, sizeof(matrix));
    int m, n;
    cin >> m >> n;

    // Eratosthenes
    matrix[1] = false;
    for (int i = 2; i <= sqrt(n); i++)
        if (matrix[i])
            for (int j = i + i; j <= n; j += i)
                matrix[j] = false;

    for (int i = m; i <= n; i++)
        if (matrix[i])
            cout << i << "\n";

    return 0;
}