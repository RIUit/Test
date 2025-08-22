#include<iostream>
using namespace std;

struct node{
	int val;
	node *left;
	node *right;
	node(int x){
		val = x;
		left = NULL;
		right = NULL;
	}
};

node *root = NULL;
node *makeNode(int x){
	return new node(x);
}
void empty_Tree(){
	root = NULL;
}
node *insert(node *root, int key){
	if(root == NULL) return makeNode(key);
	if(root->val > key)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}
bool search(node *root, int key){
	if(root == NULL) return false;
	if(root->val == key) return true;
	else if(root->val > key) return search(root->left, key);
	else return search(root->right, key);
}
node *minNode(node *root){
	node *tmp = root;;
	while(tmp != NULL && tmp->left !=NULL){
		tmp = tmp->left;
	}
	return tmp;
}
node *deleteNode(node *root, int key){
	if(root == NULL) return root;
	if(key < root->val)
		root->left = deleteNode(root->left, key);
	else if(key > root->val)
		root->right = deleteNode(root->right, key);
	else{
		if(root->left == NULL){
			node *tmp = root->right;
			delete root;
			return tmp;
		}else if(root->right == NULL){
			node *tmp = root->left;
			delete root;
			return tmp;
		}else{
			node *tmp = minNode(root->right);
			root->val = tmp->val;
			root->right = deleteNode(root->right, key);
		}
	}
}
void NLR(node *root){
	if(root == NULL) return;
	cout << root->val << " ";
	NLR(root->left);
	NLR(root->right);
}
void LNR(node *root){
	if(root == NULL) return;
	LNR(root->left);
	cout << root->val << " ";	
	LNR(root->right);
}
void LRN(node *root){
	if(root == NULL) return;
	LNR(root->left);
	LNR(root->right);
	cout << root->val << " ";	
}
int main(){
	int n;
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	
	cout << "Nhap " << n << "phan tu: ";
	for(int i = 0; i < n; i++){
		int x; cin >> x;
		root = insert(root,x);
	}
	
	cout << "Duyet NLR: "; NLR(root); cout << endl;
    cout << "Duyet LNR: "; LNR(root); cout << endl;
    cout << "Duyet LRN: "; LRN(root); cout << endl;
	
	int key;
	cout << "Nhap phan tu can tim: ";
	cin >> key;
	
	cout << (search(root,key) ? "Tim thay phan tu":"Khong tim thay phan tu") << endl;
	
	
	int xoa;
	cout << "Nhap phan tu can xoa: ";
	cin >> xoa;
	root = deleteNode(root, xoa);
	
	cout << "Inorder sau khi xoa: ";
	NLR(root);
	
	return 0;
}
