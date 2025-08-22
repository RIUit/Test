//#include<iostream>
//using namespace std;
//
//const int MAX = 100;
//
//struct DanhSach{
//	int a[MAX];
//	int n;
//};
////Ham nhap danh sach
//void nhapDS(DanhSach &ds){
//	cout << "Nhap so long phan tu: ";
//	cin >> ds.n;
//	while(ds.n < 0 || ds.n > MAX){
//		cout << "So luong khong hop le.Nhap lai di!\n";
//		cin >> ds.n;
//	}
//	for(int i = 0; i < ds.n; i++){
//		cout << "Phan tu a[" << i << "]: ";
//		cin >> ds.a[i];
//	}
//}
////Xuat danh sach
//void xuatDS(const DanhSach &ds){
//	cout << "Danh sach: ";
//	for(int i = 0; i < ds.n; i++){
//		cout << ds.a[i] << ' ';
//	}
//	cout << endl;
//}
////Tim phan tu trong danh sach
//int timPT(const DanhSach &ds, int x){
//	for(int i = 0; i < ds.n; i++)
//		if(ds.a[i] == x)
//			return i;
//	return -1;	
//}
////Them phan tu cuoi danh sach
//bool themCuoi(DanhSach &ds, int x){
//	if(ds.n >= MAX) return -1;
//	ds.a[ds.n++] = x;
//	return 1;
//}
////Xoa phan tu cuoi danh sach
//bool xoaCuoi(DanhSach &ds){
//	if(ds.n == 0) return false;
//	ds.n--;
//	return true;
//}
////
//bool xoaTaiViTri(DanhSach &ds, int i){
//	if(i < 0 || i >= ds.n) return false;
//	for(int j = i; j < ds.n - 1; j++){
//		ds.a[j] = ds.a[j + 1];
//	}
//	ds.n--;
//	return true;
//}
////Tim va xoa phan tu 
//bool timVaXoa(DanhSach &ds, int x){
//	int vt = timPT(ds, x);
//	if(vt == -1) return false;
//	xoaTaiViTri(ds, vt);
//	return true;
//}
//int main(){
//	DanhSach ds;
//	
//	nhapDS(ds);
//	xuatDS(ds);
//	
//	int x;
//	cout << "Nhap phan tu can tim: ";
//	cin >> x;
//	int vt = timPT(ds, x);
//	if(vt != -1)
//		cout << "Tim thay " << x << " tai vii tri: " << vt << endl;
//	else
//		cout << "Khong tim thay\n";
//	cout << "Nhap phan tu them cuoi: ";
//	cin >> x;
//	if(themCuoi(ds, x))
//		cout << "Them phan tu thanh cong!\n";
//	else
//		cout << "Dach sach da day.Khong the them phan tu!\n";
//	xuatDS(ds);
//	cout << "Xoa phan tu cuoi...\n";
//    xoaCuoi(ds);
//    xuatDS(ds);
//
//    cout << "Nhap vi tri can xoa: ";
//    cin >> vt;
//    if (xoaTaiViTri(ds, vt))
//        cout << "Xoa thanh cong.\n";
//    else
//        cout << "Vi tri khong hop le.\n";
//    xuatDS(ds);
//
//    cout << "Nhap gia tri can tim va xoa: ";
//    cin >> x;
//    if (timVaXoa(ds, x))
//        cout << "Tim thay va xoa thanh cong.\n";
//    else
//        cout << "Khong tim thay.\n";
//    xuatDS(ds);
//	return 0;
//}
//
//
//
//
#include <iostream>
using namespace std;

const int MAX = 100;

struct DanhSach {
    int a[MAX];
    int n;
};

// 2.1 Khai báo & kh?i t?o danh sách
void khoiTaoDS(DanhSach &ds) {
    ds.n = 0;
}

// 2.2 Thêm ph?n t? vào danh sách có th? t? (gi? nguyên th? t?)
void themPhanTu(DanhSach &ds) {
    if (ds.n >= MAX) {
        cout << "Danh sach da day.\n";
        return;
    }
    int x;
    cout << "Nhap phan tu muon them: ";
    cin >> x;

    int i = ds.n - 1;
    while (i >= 0 && ds.a[i] > x) { // d?ch sang ph?i
        ds.a[i + 1] = ds.a[i];
        i--;
    }
    ds.a[i + 1] = x;
    ds.n++;
    cout << "Them thanh cong!\n";
}

// 2.3 Xu?t danh sách
void xuatDS(const DanhSach &ds) {
    cout << "Danh sach: ";
    for (int i = 0; i < ds.n; i++) {
        cout << ds.a[i] << " ";
    }
    cout << "\n";
}

// 2.4 Tìm ki?m tu?n t? (O(n))
void timTuanTu(const DanhSach &ds) {
    int x;
    cout << "Nhap gia tri can tim: ";
    cin >> x;
    for (int i = 0; i < ds.n; i++) {
        if (ds.a[i] == x) {
            cout << "Tim thay " << x << " tai vi tri " << i << "\n";
            return;
        }
    }
    cout << "Khong tim thay.\n";
}

// 2.5 Tìm ki?m nh? phân (O(log n))
int timNhiPhan(const DanhSach &ds, int x) {
    int left = 0, right = ds.n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (ds.a[mid] == x) return mid;
        if (ds.a[mid] < x) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

void timNhiPhan_Menu(const DanhSach &ds) {
    int x;
    cout << "Nhap gia tri can tim (nhi phan): ";
    cin >> x;
    int vt = timNhiPhan(ds, x);
    if (vt != -1) cout << "Tim thay tai vi tri " << vt << "\n";
    else cout << "Khong tim thay.\n";
}

// 2.6 Tìm và xóa ph?n t?
void timVaXoa(DanhSach &ds) {
    int x;
    cout << "Nhap gia tri can tim va xoa: ";
    cin >> x;
    int vt = timNhiPhan(ds, x);
    if (vt == -1) {
        cout << "Khong tim thay.\n";
        return;
    }
    for (int i = vt; i < ds.n - 1; i++) {
        ds.a[i] = ds.a[i + 1];
    }
    ds.n--;
    cout << "Da xoa thanh cong.\n";
}

// Hàm nh?p danh sách ban d?u
void nhapDS(DanhSach &ds) {
    cout << "Nhap so luong phan tu: ";
    cin >> ds.n;
    while (ds.n < 0 || ds.n > MAX) {
        cout << "Nhap lai: ";
        cin >> ds.n;
    }
    cout << "Nhap cac phan tu tang dan: \n";
    for (int i = 0; i < ds.n; i++) {
        cin >> ds.a[i];
    }
}

int main() {
    DanhSach ds;
    khoiTaoDS(ds);

    nhapDS(ds);
    xuatDS(ds);

    themPhanTu(ds);
    xuatDS(ds);

    timTuanTu(ds);

    timNhiPhan_Menu(ds);

    timVaXoa(ds);
    xuatDS(ds);

    return 0;
}

