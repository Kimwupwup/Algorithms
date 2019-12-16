/**
 * SW Expert 8888번 - 시험
 * 
 * */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

class person {
    public:
        int number;
        int score;
        int solved;

    public:
        bool operator<(const person &p) const {
            if (this->score == p.score) {
                if (this->solved == p.solved) {
                    return this->number < p.number;
                } else {
                    return this->solved > p.solved;
                }
            } else {
                return this->score > p.score;
            }
        }
};

const int MAX = 2001;

int T;
int n, t, p;
int matrix[MAX][MAX];
int problems[MAX];
vector<person> infos;
int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> T;
    for (int test_case = 1; test_case <= T; test_case++) {
        cin >> n >> t >> p;
        infos.clear();
        infos.resize(n + 1);
        memset(problems, 0, sizeof(problems));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= t; j++) {
                cin >> matrix[i][j];
                if (matrix[i][j] == 0)
                    problems[j]++;
                else 
                    infos[i].solved++;
            }
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= t; j++) {
                infos[i].number = i;
                infos[i].score += problems[j] * matrix[i][j];                
            }
        }
        sort(infos.begin() + 1, infos.end());

        for (int i = 1; i <= n; i++) {
            if (infos[i].number == p) {
				 cout << "#" << test_case << " " << infos[i].score << " " << i << "\n";
                break;
            }               
        }
    }
    return 0;
}