#include <iostream>
using namespace std;

#define MAX 100

struct Stack {
    int a[MAX];
    int top;

    Stack() { 
        top = -1; 
    }


    bool isEmpty() { 
        return top == -1; 
    }


    bool isFull() { 
        return top == MAX - 1; 
    }

    // thêm ph?n t? vào stack
    bool push(int x) {
        if (!isFull()) {
            a[++top] = x;
            return true;
        }
        cout << "Stack day, khong the push!\n";
        return false;
    }

    
    bool pop(int &x) {
        if (!isEmpty()) {
            x = a[top--];
            return true;
        }
        cout << "Stack rong, khong the pop!\n";
        return false;
    }

    int peek() {
        if (!isEmpty()) {
            return a[top];
        }
        cout << "Stack rong!\n";
        return -1; 
    }

    // in stack
    void print() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return;
        }
        cout << "Stack: ";
        for (int i = 0; i <= top; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.print();  // Stack: 10 20 30

    cout << "Phan tu tren cung (peek): " << st.peek() << endl;

    int x;
    if (st.pop(x)) {
        cout << "Pop ra: " << x << endl;
    }

    st.print();  // Stack: 10 20

    return 0;
}

