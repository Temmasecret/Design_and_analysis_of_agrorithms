#include<iostream>
#include <fstream>
#include <time.h>
#include <limits.h>
using namespace std;
#define max 10000

int a[max];
int n;
//void sinhtest() 
//{
//	int r;
//	for (int i = 0; i < 1000; ++i) {
//		r = rand();
//		cout << r<<"  ";
//		if (i % 10 == 0)
//		{
//			cout << endl;
//		}
//	}
//}
int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
// ham input

void Input() {
	ifstream in;
	in.open("input1.txt");
	in >> n;
	cout << "So phan tu: " << n << endl;
	// khoi tao mang a
	for (int i = 1; i <= n; i++) {
		in >> a[i];
		cout << a[i] << " ";
	}
	cout << endl;
}

int MaxLeft(int i, int j, int& dau)
{
    int MaxSum = INT_MIN; // Khởi tạo giá trị tổng lớn nhất ban đầu là INT_MIN
    int Sum = 0; // Khởi tạo giá trị tổng hiện tại ban đầu là 0

    for (int k = j; k >= i; k--)
    {
        Sum += a[k]; // Cộng thêm phần tử a[k] vào tổng hiện tại

        if (MaxSum < Sum) { // Nếu tổng hiện tại lớn hơn tổng lớn nhất đã tìm thấy trước đó
            MaxSum = Sum; // Cập nhật giá trị tổng lớn nhất mới
            dau = k; // Cập nhật vị trí đầu của dãy con có tổng lớn nhất
        }
    }

    return MaxSum; // Trả về tổng lớn nhất của dãy con
}

int  MaxRight(int i, int j, int& cuoi) // tim tong max tu i sang phai den j
{
	int MaxSum = INT_MIN;
	int Sum = 0;
	for (int k = i; k <= j; k++)
	{
		Sum += a[k];
		if (MaxSum < Sum) { MaxSum = Sum; cuoi = k; }
	}
	return MaxSum;
}



//mang bat dau tu 1, truyen i=1,j=n
int MaxSub(int i, int j, int& dau, int& cuoi)
{
    int dau1, dau2, dau3, cuoi1, cuoi2, cuoi3;
    
    if (i == j) {
        dau = i;
        cuoi = i;
        return a[i];
    }
    else {
        int m = (i + j) / 2;
        int wl, wr, wm;
        
        wl = MaxSub(i, m, dau1, cuoi1); // Tìm tổng lớn nhất của dãy con bên trái (wl)
        wr = MaxSub(m + 1, j, dau2, cuoi2); // Tìm tổng lớn nhất của dãy con bên phải (wr)
        wm = MaxLeft(i, m, dau3) + MaxRight(m + 1, j, cuoi3); // Tìm tổng lớn nhất của dãy con gồm cả bên trái và bên phải (wm)
        
        int maxTam = Max(Max(wl, wr), wm); // Tìm tổng lớn nhất trong ba kết quả trên
        
        // Lưu vết
        if (maxTam == wl) {
            dau = dau1;
            cuoi = cuoi1;
        }
        else if (maxTam == wr) {
            dau = dau2;
            cuoi = cuoi2;
        }
        else if (maxTam == wm) {
            dau = dau3;
            cuoi = cuoi3;
        }
        
        return maxTam; // Trả về tổng lớn nhất của dãy con từ vị trí i đến vị trí j
    }
}


int main()
{

	int dau, cuoi;
	Input();
	int t = MaxSub(1, n, dau, cuoi);
	cout << "\nDay con lon nhat tu vi tri " << dau << " den vi tri " << cuoi << ":" << endl;
	for (int i = dau; i <= cuoi; i++)
	{
		cout << " " << a[i];
	}
	cout << endl;
	cout << "\nTong day con lon nhat la " << t;
	return 0;
}



