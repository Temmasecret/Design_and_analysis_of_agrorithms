#include<bits/stdc++.h>
using namespace std;
#define MAX 100000

int arr[MAX];
int n;
typedef struct Result{
    int value;
    int start;
    int end;
}Result;

void init()
{
    cin >> n;
    for (int i = 0; i<n;i++)
    {
        cin >> arr[i];
    }
}

Result Max_sub_array()
{
    Result Res;
    Res.start = 0;
    Res.end = 0;
    Res.value = arr[0];
    int curr_start = 0;
    int Curr_max = arr[0];
    for (int i = 1; i< n;i++)
    {
        if (Curr_max < 0) 
        {
            Curr_max = arr[i];
            curr_start = i;
        }
        else Curr_max += arr[i];
        if (Res.value < Curr_max)
        {
            Res.value = Curr_max;
            Res.start = curr_start;
            Res.end = i;
        }
    }
    return Res;
}

int main()
{
    init();
    Result ans = Max_sub_array();
    cout << "The max array start "<<ans.start << " and end "<<ans.end <<" with value " <<ans.value<<endl;
    return 0;
}