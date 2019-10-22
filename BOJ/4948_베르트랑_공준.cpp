#include <iostream>
#include <memory.h>
#include <math.h>

using namespace std;

const int MAX = (123456 * 2) + 1;
bool matrix[MAX];

int main()
{
    memset(matrix, true, sizeof(matrix));
    int n, cnt = 0;

    // Eratosthenes
    matrix[1] = false;
    for (int i = 2; i <= sqrt(MAX); i++)
        if (matrix[i])
            for (int j = i + i; j <= MAX; j += i)
                matrix[j] = false;

    while (true)
    {
        cnt = 0;
        cin >> n;
        if (n == 0)
            return 0;

        for (int i = n + 1; i <= 2 * n; i++)
            if (matrix[i])
                cnt++;

        cout << cnt << endl;
    }
}