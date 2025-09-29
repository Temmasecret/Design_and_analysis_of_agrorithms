#include <iostream>
#include<fstream>
using namespace std;

const int MAX = 100;
int n;
double W; 

double w[MAX], c[MAX]; 
int x[MAX];  
int bestX[MAX];
double maxGT = 0; 
double currW = 0, currC = 0;

void output() {
    if (currC > maxGT) {
        maxGT = currC;
        for (int i = 0; i < n; i++) bestX[i] = x[i];
    }
}

bool chapNhan(int k, int i) {
    return (currW + i * w[k] <= W);
}

void ghiNhan(int k, int i) {
    x[k] = i;
    currW += i * w[k];
    currC += i * c[k];
}

void boGhiNhan(int k, int i) {
    currW -= i * w[k];
    currC -= i * c[k];
}

void Try(int k) {
    if (k == n) {
        output();
        return;
    }
    for (int i = 0; i <= 1; i++) { 
        if (chapNhan(k, i)) {
            ghiNhan(k, i);
            Try(k + 1);
            boGhiNhan(k, i);
        }
    }
}
void nhapdl( )
{
    fstream fin;
    fin.open( "caitui1.txt",ios::in);
    if( !fin ) 
    {
        cout<<"Loi k mo duoc file.";
        return;
    }
    fin>>n>>W;
    int i;
    for( i = 1; i <= n; i++)
    {
        fin>> c[i];
    }
    for( i = 1; i <= n ; i++)
    {
        fin>>w[i];
    }
    fin.close();
}
int main() {
    // cout << "Nhap so do vat: ";
    // cin >> n;
    // cout << "Nhap trong luong toi da: ";
    // cin >> W;

    // for (int i = 0; i < n; i++) {
    //     cout << "Nhap TL va GT do vat " << i + 1 << ": ";
    //     cin >> w[i] >> c[i];
    // }

    nhapdl();

    Try(0);

    cout << "\nGia tri lon nhat: " << maxGT << endl;
    cout << "Chon cac do vat: ";
    for (int i = 0; i < n; i++) {
        if (bestX[i]) cout << i + 1 << " ";
    }
    cout << endl;

    return 0;
}

