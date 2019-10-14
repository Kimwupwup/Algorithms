#include <stack>
#include <iostream>

using namespace std;

class stack_queue {
    private:
        stack<int> en_queue;        // 넣는 queue
        stack<int> de_queue;        // 빼는 queue

    public:
        stack_queue() {}
        
        // en_queue에 쌓는다.
        void push(int n) {
            en_queue.push(n);
        }

        // de_queue에서 빠진다.
        int pop() {
            // de_queue가 비어있을 경우에 en_queue의 값들을 de_queue에 쌓는다.
            if (de_queue.empty()) {
                while (!en_queue.empty()) {
                    de_queue.push(en_queue.top());
                    en_queue.pop();
                }
            }
            // de_queue가 비어있을 경우에는 -1을 return한다.
            if (de_queue.empty()) {
                return -1;
            }
            // en_queue에 들어간 순서대로 출력된다.(FIFO)
            int out = de_queue.top();
            de_queue.pop();
            return out;
        }
};

int main() {
    stack_queue sq;
    sq.push(1);
    sq.push(2);
    sq.push(4);
    cout << sq.pop() << " ";
    cout << sq.pop() << " ";
    cout << sq.pop() << " ";
    cout << sq.pop() << " ";    // empty
    sq.push(6);
    sq.push(3);
    cout << sq.pop() << " ";
    cout << sq.pop() << " ";
    return 0;
}