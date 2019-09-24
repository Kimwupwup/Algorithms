/* FIFO(First in first out) Queue */
#include <iostream>
#include <vector>

using namespace std;

class m_queue {
    private:
        int *queue;
        int size;
        int top;
    
    public:
        m_queue(int input_size) {
            size = input_size;
            queue = (int *)malloc(size * sizeof(int));
            top = size;
        }

        void free_stack() {
            free(queue);
        }

        int pop() {
            if (top <= size - 1) return queue[top++];
            else return -1;
        }

        void push(int a) {
            if (top >= 0) queue[--top] = a;
        }

        int length() {
            return size - top;
        }
};

int main() {
    m_queue queue(5);
    queue.push(1);
    queue.push(3);
    queue.push(4);
    queue.push(2);
    queue.push(5);

    int size = queue.length();
    for (int i = 0; i < size; i++) {
        cout << queue.pop() << " ";
    }
}