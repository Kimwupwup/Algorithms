#include <iostream>
#include <math.h>

using namespace std;

int matrix[1000001] = {1};
int main()
{
    int i, a, b, c;
    for (i = 1; i <= 1000000; i++)
    {
        a = (int)(i - sqrt(i));
        b = (int)log(i);
        c = (int)(i * sin(i) * sin(i));
        matrix[i] = (matrix[a] + matrix[b] + matrix[c]) % 1000000;
    }

    while (true)
    {
        int temp;
        cin >> temp;
        if (temp == -1)
        {
            return 0;
        }
        cout << matrix[temp] << endl;
    }
    return 0;
}