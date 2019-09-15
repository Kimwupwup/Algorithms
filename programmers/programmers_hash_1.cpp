#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion)
{
    //map<string, bool> m;
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());

    for (int i = 0; i < completion.size(); i++)
    {
        if (participant[i] != completion[i])
        {
            answer = participant[i];
            return answer;
        }   
    }
    return participant[participant.size() - 1];
}

int main()
{
    vector<vector<string>> participant = {{"leo", "kiki", "eden"}, {"marina", "josipa", "nikola", "vinko", "filipa"}, {"mislav", "stanko", "mislav", "ana"}};
    vector<vector<string>> completion = {{"eden", "kiki"}, {"josipa", "filipa", "marina", "nikola"}, {"stanko", "ana", "mislav"}};
    for (int i = 0; i < participant.size(); i++) 
    {
        cout << solution(participant[i], completion[i]) << endl;
    }
    return 0;
}