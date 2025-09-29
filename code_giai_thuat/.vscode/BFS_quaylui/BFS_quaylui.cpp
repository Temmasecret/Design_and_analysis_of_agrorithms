#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

const int MAX = 100;
int s, t; // diem dau va diem cuoi
int n;
int x[MAX]; 
int bestX[MAX]; // luu loi giai tot nhat
bool visited[MAX] = {0}; // xet xem thanh pho i da di qua hay chua
int a[MAX][MAX]; // ma tran ke vo huong
int truoc[MAX] = {0};
int queue[MAX];
void output() {
	cout << t << "<--";
	int j = t-1;
	while(truoc[j]!=s-1) {
		cout << truoc[j]+1 << "<--";
		j = truoc[j];
	}
	cout << s << endl;
}

void BFS(int s, int t) {
	int u, j, dauQ = 0, cuoiQ = 0;
	queue[cuoiQ] = s; // them s vao hang doi
	cuoiQ++;
	visited[s] = 1;
	while(dauQ<cuoiQ) {
		u = queue[dauQ];
		dauQ++;
		for(j=0; j<n; j++) {
			if(a[u][j]==1 && !visited[j]) {
				queue[cuoiQ] = j;
				cuoiQ++;
				visited[j] = 1; // se chi in ra 1 duong duy nhat
				truoc[j] = u;
				if(j==t) output();	
			}
		}
	}
}
	
void readFile(const char* fileName) {
	ifstream inFile(fileName);
	if(!inFile) {
		cout << "Loi mo file";
		exit(1);
	}
	inFile >> n >> s>> t;
	for(int i=0; i<n; i++) 
		for(int j=0; j<n; j++)
			inFile >> a[i][j];
	inFile.close();
}

int main() {
	const char* fileName1 = "input1.txt";
	readFile(fileName1);
    BFS(s-1, t-1);

    return 0;
}

