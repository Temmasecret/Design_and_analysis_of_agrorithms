#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
// Mục đích của thuật toán là thực hiện được nhiều việc nhất trong danh sách những công việc có sẵn trong khoảng thời gian nhất định 
// Ý tưởng tham lam: sắp xếp việc kết thúc từ kết thúc tăng dần và chọn ( vừa ko bị chồng vừa dc nhiều việc)

typedef struct Job{
    char id[10];
    int start; 
    int end;
}Job;
int n = 0;
int Go_home;
Job CV[MAX];
void init()
{
    cin >> n;
    for (int i  = 0;i<n;i++)
    {
        cin >> CV[i].id >> CV[i].start >> CV[i].end;
    }
}

void Show_job()
{
    cout <<endl;
    for (int i = 0;i<n;i++)
    {
        cout <<"CV : "<<CV[i].id << ' '<<CV[i].start << ' '<< CV[i].end<<endl;
    }
}

// Su dung Heap sort để sắp xếp job
bool cmp_last(Job j1, Job j2)
{
    if (j1.end > j2.end) return true;
    return false;
}
void Swap_job(Job* j1, Job* j2)
{
    Job tg = *j1;
    *j1 = *j2;
    *j2 = tg;
}
void Heapify(int idx, int r)
{
    int idx1 = 2*idx + 1;
    int idx2 = 2*idx + 2;
    if (idx1 < r)
    {
        Heapify(idx1,r);
        if (cmp_last(CV[idx1],CV[idx]))
        {
            Swap_job(&CV[idx1],&CV[idx]);
        }
    }
    if (idx2 < r)
    {
        Heapify(idx2,r);
        if(cmp_last(CV[idx2],CV[idx]))
        {
            Swap_job(&CV[idx2],&CV[idx]);
        } 
    }
}

void Heap_sort()
{
    for (int i = n; i>0;i--)
    {
        Heapify(0,i);
        Swap_job(&CV[i-1],&CV[0]);
    }
}

void Choose_job()
{
    vector<Job> data;  
    int curr_end = 0;
    for (int i = 0; i<n;i++)
    {
        if (CV[i].start > curr_end)
        {
            data.push_back(CV[i]);
            curr_end = CV[i].end;
        }
    } 
    cout << "\tCong viec\tBat dau\tKet thuc"<<endl; 
    for (auto CVi : data)
    {
        cout <<"\t" <<CVi.id<<"\t\t"<<CVi.start<<"\t"<<CVi.end << endl;
    }
}
int main()
{
    init();
    Show_job();
    Heap_sort();
    Show_job();
    Choose_job();
    return 0;
}
/*
11
a1 1 3
a2 4 6
a3 2 7 
a4 9 10
a5 5 17
a6 8 14
a7 13 16
a8 11 15
a9 3 8
a10 15 20
a11 6 11
*/