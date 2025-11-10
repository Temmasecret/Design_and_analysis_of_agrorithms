#include<bits/stdc++.h>
using namespace std;

typedef struct save
{
    int start;
    int end;
    int cost;
}save;

save Max_sub_array(int arr[], int l, int r)
{
    int curr_start = l;
    save res;
    res.start = l;
    int curr_max = arr[l];
    res.cost = arr[l];
    res.end = l;
    for (int i = l+1; i<=r ; i++)
    {
        if (curr_max < 0)
        {
            curr_max = arr[i];
            curr_start = i;
        }
        else 
        {
            curr_max += arr[i];
        }
        if (curr_max > res.cost)
        {
            res.cost = curr_max;
            res.start = curr_start;
            res.end = i;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i< n;i++)
    {
        cin >> arr[i];
    }
    save res = Max_sub_array(arr,0,n-1);
    cout<< res.start + 1<<' '<<res.end + 1<<' '<<res.cost<<endl;
}