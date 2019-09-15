#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int answer = 0;
vector<int> counter;

void DFS(int idx, int product)
{
    product *= counter[idx];
    answer += product;
    for (int i = idx + 1; i < counter.size(); i++)
    {
        DFS(i, product);
    }
}

int solution(vector<vector<string>> clothes)
{
    counter.clear();
    answer = 0;
    map<string, vector<string>> m;
    
    for (vector<string> v : clothes)
    {
        m[v[1]].push_back(v[0]);
    }

    map<string, vector<string>>::iterator iter;
    for (iter = m.begin(); iter != m.end(); ++iter)
    {
        counter.push_back((iter->second).size());
    }

    // for (int temp : counter)
    // {
    //     answer += temp;
    // }
    
    for (int i = 0; i < counter.size(); i++)
    {
        DFS(i, 1);
    }
    return answer;
}

int main()
{
    vector<vector<vector<string>>> clothes =
        {{{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}},
         {{"crow_mask", "face"}, {"blue_sunglasses", "face"}, {"smoky_makeup", "face"}}};

    for (vector<vector<string>> test_set : clothes)
    {
        cout << "answer : " <<  solution(test_set) << endl;
    }
    return 0;
}