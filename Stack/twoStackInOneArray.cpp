#include <iostream>
using namespace std;

class Stack {
public:
    int *arr;
    int size;
    int top1;
    int top2;

    Stack(int Capacity) {
        size = Capacity;
        arr = new int[size];
        top1 = -1;
        top2 = size;
    }

    void push1(int val) {
        if (top1 + 1 == top2) {
            cout << "Overflow in Stack 1" << endl;
        } else {
            arr[++top1] = val;
        }
    }

    void push2(int val) {
        if (top1 + 1 == top2) {
            cout << "Overflow in Stack 2" << endl;
        } else {
            arr[--top2] = val;
        }
    }

    void pop1() {
        if (top1 == -1) {
            cout << "Underflow in Stack 1" << endl;
        } else {
            top1--;
        }
    }

    void pop2() {
        if (top2 == size) {
            cout << "Underflow in Stack 2" << endl;
        } else {
            top2++;
        }
    }

    void print() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        if (top1 != -1)
            cout << "Top1 element: " << arr[top1] << endl;
        else
            cout << "Stack 1 is empty" << endl;

        if (top2 != size)
            cout << "Top2 element: " << arr[top2] << endl;
        else
            cout << "Stack 2 is empty" << endl;
    }

    ~Stack() {
        delete[] arr;
    }
};

int main() {
    Stack s(7);

    s.push1(11);
    s.push1(12);
    s.push2(17);
    s.push2(16);
    s.push1(13);
    s.push2(14);
    s.push1(12);   // overflow
    s.push2(18);   // overflow

    s.print();

    s.pop1();
    s.pop2();

    s.print();
    return 0;
}
