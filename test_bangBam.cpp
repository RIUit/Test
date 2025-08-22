#include<iostream>
#define M 101
using namespace std;

struct node{
	int val;
	node *next;
	node(int x){
		val = x;
		next =NULL;
	}
};
struct hashTable{
	node *a[M];
};
void init(hashTable &ht){
	for(int i = 0; i < M; i++){
		ht.a[i] = NULL;
	}
}
int hashFunc(int key){
	return key % M;
}	
node *insert(hashTable &ht, int key){
	int h = hashFunc(key);
	node *newNode = new node(key);
	if(ht.a[h] == NULL)
		 return ht.a[h] = newNode;
	else{
		node *tmp = ht.a[h];
		while(tmp->next !=NULL){
			tmp = tmp->next;
		}
		return tmp->next = newNode;
	}
}
bool search(hashTable &ht, int key){
	int h = hashFunc(key);
	node *tmp = ht.a[h];
	while(tmp != NULL){
		if(tmp->val == key)
			return true;
		tmp = tmp->next;
	}
	return false;
}
void remove(hashTable &ht, int key){
	int h = hashFunc(key);
	node *tmp = ht.a[h];
	node *r = NULL;
	while(tmp != NULL && tmp->val != key){
		r = tmp;
		tmp = tmp->next;
	}
	if(tmp == NULL) return;
	if(r == NULL){
		ht.a[h] = tmp->next;
	}else{
		r->next = tmp->next;
	}
	delete tmp;
}
void nhap(hashTable &ht){
	int x, n;
	cout << "Nhap sp phan tu: ";
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		insert(ht,x);
	}
}
void xuat(hashTable &ht){
	for(int i = 0; i < M; i ++){
		node *tmp = ht.a[i];
		while(tmp != NULL){
			cout << tmp->val << " ";
			tmp = tmp->next;
		}
	}
	cout << endl;
}
int main(){
	
	
	
	
	
	return 0;
}
