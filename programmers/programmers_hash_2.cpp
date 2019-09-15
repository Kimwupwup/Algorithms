#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool solution(vector<string> phone_book)
{
    bool answer = true;
    for (int i = 0; i < phone_book.size(); i++)
    {
        for (int j = 0; j < phone_book.size(); j++)
        {
            if (i == j) continue;
            if (phone_book[j].find(phone_book[i]) == 0) return false;
        }
    }
    return answer;
}

int main()
{
    vector<vector<string>> phone_book = {{"119", "97674223", "1195524421"}, {"123", "456", "789"}, {"12", "123", "1235", "567", "88"}};
    for (int i = 0; i < phone_book.size(); i++)
    {
        cout << solution(phone_book[i]) << endl;
    }
    return 0;
}