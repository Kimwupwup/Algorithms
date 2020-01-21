/**
 * 백준 18258번 - 큐 2
 * 
 * TODO:
 * 큐, 데큐
 * */
#include <iostream>
#include <deque>

using namespace std;

deque<int> dq;
int n;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    cin >> n;
    while (n--) {
        string command;
        int num;

        cin >> command;
        if (command == "push") {
            cin >> num;
            dq.push_back(num);
        }
        else if (command == "pop") {
            if (dq.empty()) cout << -1 << "\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (command == "size") {
            cout << dq.size() << "\n";
        }
        else if (command == "empty") {
            cout << (dq.empty() ? 1 : 0) << "\n";
        }
        else if (command == "front") {
            cout << (dq.empty() ? -1 : dq.front()) << "\n";
        }
        else if (command == "back") {
            cout << (dq.empty() ? -1 : dq.back()) << "\n";
        }
    }
    return 0;
}