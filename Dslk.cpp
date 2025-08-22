#include<iostream>
using namespace std;

struct node{
    int data;
    node *next;
    node(int x){
        data = x;
        next = NULL;
    }
};

void duyet(node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int sz(node *head){
    int cnt = 0;
    while(head != NULL){
        cnt++;
        head = head->next;
    }
    return cnt;
}

void themDau(node *&head, int x){
    node *newnode = new node(x);
    newnode->next = head;
    head = newnode;
}

void themCuoi(node *&head, int x){
    node *newnode = new node(x);
    if(head == NULL){
        head = newnode;
        return;
    }
    node *tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;    
    }
    tmp->next = newnode;
}

void themGiua(node *&head, int x, int k){
    if(k < 1 || k > sz(head) + 1) return;
    node *newnode = new node(x);
    if(k == 1){  // thêm d?u
        newnode->next = head;
        head = newnode;
        return;
    }
    node *tmp = head;
    for(int i = 1; i <= k - 2; i++){
        tmp = tmp->next;
    }
    newnode->next = tmp->next;
    tmp->next = newnode;
}

void xoaDau(node *&head){
    if(head == NULL) return;
    node *tmp = head;
    head = head->next;
    delete tmp;
}

void xoaCuoi(node *&head){
    if(head == NULL) return;
    else if(head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    node *tmp = head;
    while(tmp->next->next != NULL){
        tmp = tmp->next;
    }
    node *last = tmp->next;
    tmp->next = NULL;
    delete last;
}

void xoaGiua(node *&head, int k){
    if(head == NULL) return;
    else if(k < 1 || k > sz(head)) return;
    if(k == 1){
        xoaDau(head);
        return;
    }
    node *tmp = head;
    for(int i = 1; i <= k - 2; i++){
        tmp = tmp->next;
    }
    node *xoa = tmp->next;
    tmp->next = xoa->next;
    delete xoa;
}

int main(){
    node *head = NULL;

    themDau(head, 1);
    themCuoi(head, 3);
    themGiua(head, 2, 2); // chèn s? 2 vào gi?a

    duyet(head); // 1 2 3

    xoaGiua(head, 2); // xóa s? 2
    duyet(head); // 1 3

    xoaDau(head); // xóa 1
    duyet(head); // 3

    xoaCuoi(head); // xóa 3
    duyet(head); // r?ng

    return 0;
}

