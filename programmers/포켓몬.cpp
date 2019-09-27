#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
	int answer = 0;
    int n = nums.size() / 2;

    for (int i = 0; i < nums.size(); i++) {
        s.insert(nums[i]);
    }

    answer = min((int)s.size(), n);
    
	return answer;
}