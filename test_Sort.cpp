#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

const int MAX = 100;

void khoiTao(int a[], int n, int min, int max){
	for(int i = 0; i < n; i++){
		a[i] = rand() % (max - min + 1) + min;
	}
}
void inMang(int a[], int n){
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}
void swap(int &a, int &b){
	int c = a;
	a = b;
	b = c;
}
void selectionSort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		int pos = i;
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[pos])
				pos = j;
		}
		swap(a[i],a[pos]);
	}
}
void interChangeSort(int a[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1; j < n; j++){
			if(a[j] < a[i])
				swap(a[j], a[i]);
		}
	}
}
void bubbleSort(int a[], int n){
	for(int i  = 0; i < n - 1; i++){
		for(int j = 0; j < n - i - 1; j++){
			if(a[j] > a[j + 1])
				swap(a[j], a[j + 1]);
		}
	}
}
void insertionSort(int a[], int n){
	for(int i = 1; i < n; i++){
		int pos = i - 1, val = a[i];
		while(pos >= 0 && a[pos] > val){
			a[pos + 1] = a[pos];
			pos--;
		}
		a[pos + 1] = val;
	}
}
void quickSort(int a[], int left, int right){
	int m = a[((left+right) / 2)];
	int i = left, j = right;
	while(i <= j){
		while(a[i] < m) i++;
		while(a[j] > m) j--;
		if(i <= j){
			swap(a[i],a[j]);
			i++; j--;
		}
	}
	if(j > left) quickSort(a,left, j);
	if(i < right) quickSort(a,i, right);
}
void shift(int a[], int i, int n){
	int j = 2 * i + 1;
	if(j >= n) return;
	if(j + 1 < n)
		if(a[j] < a[j + 1])
			j++;
	if(a[i] >= a[j]) return;
	else{
		swap(a[i], a[j]);
		shift(a, j, n);
	}	
}
void heapSort(int a[], int n){
	for(int i = n / 2 - 1; i >=0; i--){
		shift(a, i, n);
	}
	for(int j = n - 1; j >= 0; j--){
		swap(a[0],a[j]);
		shift(a, 0, j);
	}
}
void merge(int a[], int l, int m, int r){
	int n1 = m - l + 1;
	int n2 = r - m;
	int *x = new int[n1];
	int *y = new int[n2];
	for(int i = 0; i < n1; i++){
		x[i] = a[l + i];
	}
	for(int i = 0; i < n2; i++){
		y[i] = a[m + i + 1];
	}
	int cnt = l;
	int i = 0, j = 0;
	while(i < n1 && j < n2){
		if(x[i] <= y[j]){
			a[cnt++] = x[i++];
		}else
			a[cnt++] = y[j++];
	}
	while( i < n1){
		a[cnt++] = x[i++];
	}
	while( j < n2){
		a[cnt++] = y[j++];
	}
}
void mergeSort(int a[], int l, int r){
	if(l < r){
		int m = (l + r) / 2;
		mergeSort(a, l, m);
		mergeSort(a, m + 1, r);
		merge(a,l,m,r);
	}
	
}
int main(){
	int a[MAX];
	int n;
	srand(time(0));
	cout << "Nhap so luong phan tu: ";
	cin >> n;
	khoiTao(a, n, 10, 50);
	cout << "Mang khoi tao ban dau: \n";
	inMang(a,n);
	
	cout << "Mang sao khi sap xep: \n";
	mergeSort(a, 0,n - 1);
	inMang(a,n);
	
	
	
	
	return 0;
}
