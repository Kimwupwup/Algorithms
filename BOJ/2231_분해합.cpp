#include <iostream>
#include <string>
using namespace std;
int main()
{
    int num = 0;
    int sum = 0;
    cin >> num;
    for (int i = 0; i <= num; i++)
    {
        string temp = to_string(i);
        sum = i;
        for (char c : temp)
        {
            sum += c - '0';
        }
        if (sum == num)
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}