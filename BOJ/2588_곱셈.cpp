#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int num;
    cin >> num >> str;

    for (int i = str.size() - 1; i >= 0; i--)
    {
        cout << (num * (str[i] - '0')) << endl;
    }
    cout << (num * stoi(str)) << endl;
}