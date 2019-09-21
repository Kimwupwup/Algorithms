#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> people, int limit)
{
    int answer = 0;
    sort(people.begin(), people.end(), greater<int>());
    int left = 0;
    int right = people.size() - 1;

    while (left < right) {
        if (people[left] + people[right] <= limit) {
            right--;
        }
        left++;
        answer++;
    }
    if (left == right) {
        answer++;
    }
    return answer;
}

int main()
{
    vector<vector<int>> people = {
        {70, 50, 80, 50},
        {70, 80, 20, 20, 10}};

    for (vector<int> p : people)
    {
        cout << solution(p, 100) << endl;
    }
}