
// #include <iostream>
// #include <fstream>
// using namespace std;

// int n;
// int a[100][100];

// void init() {
//     fstream f;
//     f.open("input1.txt", ios::in);
//     if (!f) {
//         cout << "Loi khong mo duoc file.";
//         return;
//     }
//     f >> n;
    
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= n; j++) {
//             f >> a[i][j];
//         }
//         a[i][i] = 100; // Đảm bảo đường đi đến chính nó là vô cùng lớn
//     }
//     f.close();
// }

// void hd() {
//     int daxet[100] = {0};
//     int khoangcach[100]; // Lưu khoảng cách ngắn nhất
//     int lientruoc[100]; // Lưu đỉnh trước đó trong đường đi
//     int bd;

//     cout << "Nhap diem bat dau: ";
//     cin >> bd;

//     for (int i = 1; i <= n; i++) {
//         daxet[i] = 0;
//         khoangcach[i] = 10000;
//         lientruoc[i] = -1; // Ban đầu không có đường đi
//     }

//     khoangcach[bd] = 0;
//     daxet[bd] = 1;

//     for (int j = 1; j <= n; j++) {
//         khoangcach[j] = a[bd][j];
//         if (khoangcach[j] < 10000) {
//             lientruoc[j] = bd;
//         }
//     }

//     for (int count = 1; count < n; count++) {
//         int min = 10000;
//         int nextNode = -1;

//         for (int j = 1; j <= n; j++) {
//             if (!daxet[j] && khoangcach[j] < min) {
//                 min = khoangcach[j];
//                 nextNode = j;
//             }
//         }

//         if (nextNode == -1) break; // Không có đường đi tiếp

//         daxet[nextNode] = 1;

//         for (int j = 1; j <= n; j++) {
//             if (!daxet[j] && khoangcach[j] > khoangcach[nextNode] + a[nextNode][j]) {
//                 khoangcach[j] = khoangcach[nextNode] + a[nextNode][j];
//                 lientruoc[j] = nextNode;
//             }
//         }
//     }

//     cout << "Duong di ngan nhat tu " << bd << " den " << n << " la: \n";
//     int cur = n;
//     cout << n;
//     while (lientruoc[cur] != -1) {
//         cout << " <-- " << lientruoc[cur];
//         cur = lientruoc[cur];
//     }
//     cout << endl;
// }

// int main() {
//     init();
//     hd();
// }
