#include<iostream>
using namespace std;

struct node{
	int val;
	node *next;
	node(int x){
		val = x;
		next = NULL;
	}
};
struct queue{
	node *l;
	node *r;
};
void init(queue &q){
	q.l = NULL;
	q.r = NULL;
}
bool isEmpty(queue &q){
	return q.l == NULL;
}
bool enqueue(queue &q,int x){
	node *newNode = new node(x);
	if (isEmpty(q)) {
        q.l =  newNode;
        q.r = newNode;
    } else {
        q.r->next = newNode;
        q.r = newNode;
    }
    return true;
}
bool dequeue(queue &q, int &x) {
    if (isEmpty(q)) {
        cout << "Queue rong, khong the xoa!\n";
        return false;
    }
    node *tmp = q.l;
    x = tmp->val;
    q.l = q.l->next;
    if (q.l == NULL) q.r = NULL; // N?u h?t thì rear = NULL
    delete tmp;
    return true;
}
void display(queue q) {
    if (isEmpty(q)) {
        cout << "Queue rong\n";
        return;
    }
    cout << "Queue: ";
    node *tmp = q.l;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
void clearQueue(queue &q) {
    node *tmp;
    while (q.l != NULL) {
        tmp = q.l;
        q.l = q.l->next;
        delete tmp;
    }
    q.r = NULL;
}
int main(){
	queue q;
    init(q);

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);

    display(q);

    int x;
    dequeue(q, x);
    cout << "Phan tu lay ra: " << x << endl;

    display(q);

    clearQueue(q);
    display(q);

    return 0;
	
	
}
