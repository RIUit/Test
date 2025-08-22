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
void empty_tree(){
	root = NULL;
}
bool search(node *root, int key){
	if(root == NULL) return false;
	if(root->val == key) return true;
	else if(root->val > key)
		return search(root->left, key);
	else
		return search(root->right, key);
}
node *insert(node *root, int key){
	if(root == NULL) return new node(key);
	if(root->val > key)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
}
node *minNode(node *root){
	node *tmp = root;
	while(tmp != NULL && tmp->left != NULL)
		tmp = tmp->left;
	return tmp;
}
node *deleteNode(node *root, int key){
	if(root == NULL) return root;
	if(root->val > key)
		root->left = deleteNode(root->left, key);
	else if(root->val < key)
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
	return root;
}
int main(){
	
	
	
	return 0;
}
