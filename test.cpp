//#include <iostream>
//using namespace std;
//
//#define MAX 100  
//
//struct Stack {
//    int arr[MAX]; 
//    int top;      
//
// 
//    Stack() {
//        top = -1;
//    }
//
//   
//    bool isEmpty() {
//        return top == -1;
//    }
//
//   
//    bool isFull() {
//        return top == MAX - 1;
//    }
//
//    // Thêm ph?n t? vào stack (push)
//    void push(int x) {
//        if (isFull()) {
//            cout << "Stack day, khong the them phan tu!\n";
//            return;
//        }
//        arr[++top] = x;
//    }
//
//    // L?y ph?n t? ra kh?i stack (pop)
//    int pop() {
//        if (isEmpty()) {
//            cout << "Stack rong, khong the lay phan tu!\n";
//            return -1; // giá tr? báo l?i
//        }
//        return arr[top--];
//    }
//
//    // Xem ph?n t? d?nh (peek)
//    int peek() {
//        if (isEmpty()) {
//            cout << "Stack rong!\n";
//            return -1;
//        }
//        return arr[top];
//    }
//};
//
//int main() {
//    Stack st;
//
//    st.push(10);
//    st.push(20);
//    st.push(30);
//
//    cout << "Phan tu tren dinh: " << st.peek() << endl;
//
//    cout << "Pop: " << st.pop() << endl;
//    cout << "Pop: " << st.pop() << endl;
//
//    cout << "Phan tu tren dinh: " << st.peek() << endl;
//
//    return 0;
//}
#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
};


struct Stack {
    Node* top; 

    // Hàm kh?i t?o
    Stack() {
        top = NULL;
    }

    // Ki?m tra stack r?ng
    bool isEmpty() {
        return top == NULL;
    }

    // Thêm ph?n t? vào stack (push)
    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->next = top; // node m?i tr? t?i d?nh cu
        top = newNode;       // c?p nh?t d?nh
    }

    // L?y ph?n t? ra kh?i stack (pop)
    int pop() {
        if (isEmpty()) {
            cout << "Stack rong, khong the pop!\n";
            return -1;
        }
        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return value;
    }

    // Xem ph?n t? trên d?nh
    int peek() {
        if (isEmpty()) {
            cout << "Stack rong!\n";
            return -1;
        }
        return top->data;
    }

    // Gi?i phóng b? nh?
    void clear() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Phan tu tren dinh: " << st.peek() << endl;

    cout << "Pop: " << st.pop() << endl;
    cout << "Pop: " << st.pop() << endl;

    cout << "Phan tu tren dinh: " << st.peek() << endl;

    st.clear(); // d?n d?p b? nh?

    return 0;
}


