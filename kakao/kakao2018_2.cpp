#include <iostream>
#include <math.h>
#include <vector>
#include <string>

using namespace std;
void solution(vector<string> dartResult)
{
    vector<int> ret;
    for (string quest : dartResult)
    {
        ret.clear();
        int cal = 0;
        for (char temp : quest)
        {
            if (temp >= '1' && temp <= '9')
            {
                ret.push_back(temp - '0');
                continue;
            }
            else if (temp == '0')
            {
                if (ret[ret.size() - 1] == 1) ret[ret.size() - 1] = 10;
                else ret.push_back(0);;
                continue;
            }

            

            if (temp == 'S')
            {
                ret[ret.size() - 1] = pow(ret[ret.size() - 1], 1);
                continue;
            }                
            else if (temp == 'D')
            {
                ret[ret.size() - 1] = pow(ret[ret.size() - 1], 2);
                continue;
            }
            else if (temp == 'T')
            {
                ret[ret.size() - 1] = pow(ret[ret.size() - 1], 3);
                continue;
            }

            if (temp == '*')
            {
                ret[ret.size() - 1] = ret[ret.size() - 1] * 2;
                
                if (ret.size() - 2 >= 0)
                    ret[ret.size() - 2] *= 2;
                
                continue;
            }

            if (temp == '#')
            {
                ret[ret.size() - 1] *= -1;
                continue;
            }
            
            

        }
        cout << ret[0] + ret[1] + ret[2] << endl;
    }
}
int main()
{
    vector<string> dartResult = {"1S2D*3T", "1D2S#10S", "1D2S0T", "1S*2T*3S", "1D#2S*3S", "1T2D3D#", "1D2S3T*"};
    solution(dartResult);
    return 0;
}