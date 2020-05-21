/**
 * 백준 1476번 - 날짜 계산
 * 
 * */
#include <iostream>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    int matrix[3];
    for (int i = 0; i < 3; i++)
        cin >> matrix[i];

    int temp[3] = {1, 1, 1};

    int ret = 1;
    while (true)
    {
        if (matrix[0] == temp[0] && matrix[1] == temp[1] && matrix[2] == temp[2]) break;
        temp[0] = (temp[0] + 1) % 16 == 0 ? 1 : temp[0] + 1;
        temp[1] = (temp[1] + 1) % 29 == 0 ? 1 : temp[1] + 1;
        temp[2] = (temp[2] + 1) % 20 == 0 ? 1 : temp[2] + 1;
        ret++;
    }
    cout << ret << "\n";


    return 0;
}