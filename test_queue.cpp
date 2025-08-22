#include<iostream>
#define MAX 100
using namespace std;

struct queue{
	int a[MAX];
	int star;
	int end;
};
void init(queue &q){
	q.star = 0;
	q.end = -1;
}
bool isEmpty(queue &q){
	return q.star > q.end;
}
bool isFull(queue &q){
	return q.end - q.star + 1 == MAX;
}
bool insertQueue(queue &q, int x){
	if(isFull(q)){
		cout << "Queue day!Khong the them duoc nua!\n";
		return false;
	}
	q.a[++q.end] = x;
	return true;
}
bool deleteQueue(queue &q, int &x){
	if (isEmpty(q)) {
        cout << "Queue rong, khong the xoa!\n";
        return false;
    }
    x = q.a[q.star];
    q.star++;
    return true;
}
void display(queue q){
	if(isEmpty(q)){
		cout << "Queue rong!\n";
	}
	cout << "Queue: ";
	for(int i = q.star; i < q.end; i++){
		cout << q.a[i] << " ";
	}
	cout << endl;
}
int main(){
	queue q;
	init(q);
	int n,x;
	cout << "Nhap n: ";
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		insertQueue(q,x);
	}
	display(q);
	int y;
    if (deleteQueue(q, y)) cout << "Lay ra: " << y << endl;
    if (deleteQueue(q, y)) cout << "Lay ra: " << y << endl;

    display(q);

    if (isEmpty(q)) cout << "Queue dang rong\n";
    else cout << "Queue con phan tu\n";
	
	
	
	
	return 0;
}
