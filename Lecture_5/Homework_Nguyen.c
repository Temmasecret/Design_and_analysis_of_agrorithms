#include <limits.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>


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

int Max_sub_arr_n_2(int arr[],int l,int r)
{
    int Max = INT_MIN;
    int size = r-l;
    int test_case[size];
    memset(test_case,0,sizeof(test_case));
    for (int i = 0;i<size;i++)
    {
        if (i == 0) test_case[i] = arr[l+i];
        else if (arr[l+i] >= 0 && test_case[i-1] > 0) test_case[i] = test_case[i-1] + arr[l+i];
        else test_case[i] = arr[l+1];
    }
    for (int i = 0;i<size;i++)
    {
        if (Max < test_case[i]) Max = test_case[i];
        printf("%d\n",test_case[i]);
    }
    return Max;
}

Result Max_sub_arr_O_n(int arr[],int l, int r)
{
    int max_so_far = INT_MIN;
    int Max_ending_here = 0;
    int begin = 0;
    int end = 0;
    Result res;
    for (int i = l;i<=r;i++)
    {
        Max_ending_here += arr[i];
        if (Max_ending_here < arr[i])
        {
            Max_ending_here = arr[i];
            begin = i;
        }
        if (max_so_far < Max_ending_here)
        {
            max_so_far = Max_ending_here;
            res.sum = max_so_far;
            res.begin = begin;
            res.end = i;
        }
    }
    return res;
    
}    
// int** mul_same_perfect_array(int **arr1,int **arr2, int n)
// {
//     int** arr_mul = (int **)malloc(sizeof(int*)*n);
//     if (*arr_mul == NULL) return NULL;
//     for (int i =0;i<n;i++)
//     {
//         arr_mul[i] = (int*)malloc(sizeof(int)*n);
//         memset(arr_mul[i],0,sizeof(int)*n);
//         if (arr_mul[i] == NULL) return NULL;
//     }
//     if (n == 2)
//     {
//         for (int i = 0;i<2;i++)
//         {
//             for (int j = 0; j<2 ;j++)
//             {
              
//             }
//         }
//     }
//     return arr_mul;
// }

int main()
{
    Result res;
    int A[] = {-98,54,67, 65,-879,78,65,21,-6,67};
    res = Max_Sub_array(A,0,9);
    printf("The max value of sub array is %d\n",res.sum);
    printf("The sub arr max from %d to %d \n",res.begin,res.end);
    res = Max_sub_arr_O_n(A,0,9);
    printf("The max value of sub array is %d\n",res.sum);
    printf("The sub arr max from %d to %d \n",res.begin,res.end);
    return 0;
}