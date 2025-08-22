#include<iostream>
using namespace std;

#define MAX 100

struct stack{
	int a[MAX];
	int top;
	
	stack(){
		top = -1;
	}
	bool isEmpty(){
		return top == -1;
	}
	bool isFull(){
		return top == MAX - 1;
	}
	bool push(int x){
		if(!isFull()){
			a[++top] = x;
			return 1;
		}
		cout << "Stack da day!Khong them duoc nua!\n";
		return 0;
	}
	bool pop(int &x){
		if(!isEmpty()){
			x = a[top--];
			return 1;
		}
		cout <<"Stack rong!\n";
		return 0;
	}
	int peek()
};

int main(){
	
	
	
	
	
	
	return 0;
}
