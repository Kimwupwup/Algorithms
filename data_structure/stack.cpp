/* LIFO(Last in first out) Stack */
#include <iostream>
#include <vector>

using namespace std;

class m_stack {
    private:
        int *stack;
        int size;
        int top;
    
    public:
        m_stack(int input_size) {
            size = input_size;
            stack = (int *)malloc(size * sizeof(int));
            top = -1;
        }

        void free_stack() {
            free(stack);
        }

        int pop() {
            if (top >= 0) return stack[top--];
            else return -1;
        }

        void push(int a) {
            if (top < size - 1) stack[++top] = a;
        }

        int length() {
            return top + 1;
        }
};

int main() {
    m_stack stack(5);
    stack.push(1);
    stack.push(3);
    stack.push(4);
    stack.push(2);
    stack.push(5);

    int size = stack.length();
    for (int i = 0; i < size; i++) {
        cout << stack.pop() << " ";
    }
}