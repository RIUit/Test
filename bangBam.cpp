#include<iostream>
#define M 107
using namespace std;

struct node{
	int key;
	node *next;
	node(int x){
		key = x;
		next = NULL;
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
void insert(hashTable &ht, int key){
	int index = hashFunc(key);
	node *p = new node(key);
	if(ht.a[index] == NULL){
		ht.a[index] = p;
	}else{
		node *tmp = ht.a[index];
		while(tmp->next != NULL){
			tmp = tmp->next;
		}
		tmp->next = p;
	}
}
bool search(hashTable ht, int key){
	int index = hashFunc(key);
	node *tmp = ht.a[index];
	while(tmp != NULL){
		if(tmp->key == key)
			return true;
			tmp = tmp->next;
	}
	return false;
}
void remove(hashTable &ht, int key){
	int index = hashFunc(key);
	node *tmp = ht.a[index];
	node *r = NULL;
	while(tmp != NULL && tmp->key != key){
		r = tmp;
		tmp =  tmp->next;
	}
	if(tmp == NULL) return;
	if(r == NULL){
		ht.a[index] = tmp->next;
	}else{
		r->next = tmp->next;
	}
	delete tmp;
}
void nhap(hashTable &ht){
	int x, n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	for(int i = 0; i < n; i++){
		cout << "Phan tu thu " << i + 1 <<": ";
		cin >> x;
		insert(ht,x);
	}
}
void xuat(hashTable ht){
	cout << "\nCac phan tu da nhap: ";
	for(int i = 0; i < M; i++){
		node *tmp = ht.a[i];
		while(tmp != NULL){
			cout << tmp->key << " ";
			tmp = tmp->next;
		}
	}
	cout << endl;
}
int main(){
	hashTable ht;
	init(ht);
	
	nhap(ht);
    xuat(ht);
	
	int x;
    cout << "\nNhap so can tim: ";
    cin >> x;
    cout << (search(ht, x) ? "Tim thay" : "Khong tim thay") << endl;

    cout << "\nNhap so can xoa: ";
    cin >> x;
    remove(ht, x);

    cout << "\nBang bam sau khi xoa:" << endl;
    xuat(ht);
	
	
	return 0;
}
