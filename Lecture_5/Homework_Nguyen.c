#include <limits.h>
#include<stdio.h>
#include<stdlib.h>

struct Result{
    int sum;
    int begin;
    int end;
};

typedef struct Result Result;

Result Max_crossing_sum(int arr[], int l,int r, int mid)
{
    int sum =0;
    int Max_left = INT_MIN;
    // Max arr in the left side
    Result res;
    res.begin = mid;
    for (int i = mid;i>=l;i--)
    {
        sum += arr[i];
        if (sum > Max_left) 
        {
            Max_left = sum;
            res.begin = i;
        } 
    }
    sum = 0;
    int Max_right = INT_MIN;
    // Max arr in the right side
    for (int i = mid + 1; i<=r;i++)
    {
        sum += arr[i];
        if (sum > Max_right) 
        {
            Max_right = sum;
            res.end = i;
        }
    }
    res.sum = Max_left + Max_right;
    return res;
}

Result Max_Sub_array(int arr[], int l, int r)
{
    Result res;
    // If the array have onlyone value 
    if (l == r) 
    {
        res.sum = arr[l];
        res.begin = l;
        res.end = r;
        return res;
    }
    // Find the mid value
    int mid = (r - l)/2 + l;
    // 1 The max array in all the left
    // 2.The max array in all the right
    // 3.The max array in the middle 
    Result WL = Max_Sub_array(arr,l,mid);
    Result WR = Max_Sub_array(arr,mid+1,r);
    Result WM = Max_crossing_sum(arr,l,r,mid);
    // Choose the maximum value of all 
    if (WL.sum >= WR.sum && WL.sum >= WM.sum) return WL;
    else if (WR.sum >= WL.sum && WR.sum >= WM.sum) return WR;
    else return WM;
}

int main()
{
    Result res;
    int A[] = {-98,54,67, 65,-879,78,65,21,-6,67};
    res = Max_Sub_array(A,0,9);
    printf("The max value of sub array is %d\n",res.sum);
    printf("The sub arr max from %d to %d \n",res.begin,res.end);
    return 0;
}