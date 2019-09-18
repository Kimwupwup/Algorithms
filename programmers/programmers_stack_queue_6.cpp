#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    for(int i = 0; i<prices.size(); i++){
        for(int j = i+1; j<prices.size(); j++){
            if(prices[i]<=prices[j]){
                answer[i]++;
            }
            else{
                answer[i]++;
                break;
            }
        }
    }
    return answer;
}

vector<int> solution1(vector<int> prices)
{
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    for(int i=0;i<size;i++){
        while(!s.empty()&&prices[s.top()]>prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty()){
        answer[s.top()] = size-s.top()-1;
        s.pop();
    }
    return answer;
}

int main()
{
    vector<int> prices = {4,3,2,1};
    vector<int> ret = solution(prices);
    for (int temp : ret)
    {
        cout << temp << " ";
    }
    cout << endl;
    vector<int> r = solution1(prices);
    for (int temp : r)
    {
        cout << temp << " ";
    }
}