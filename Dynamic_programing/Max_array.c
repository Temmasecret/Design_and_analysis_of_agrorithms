#include <stdio.h>

#define MIN -1000000

int max_val(int a, int b)
{
    return a > b ? a : b;
}

int main()
{
    int n;
    scanf("%d",&n);
    int array[n];
    for (int i = 0; i< n;i++)
    {
        scanf("%d",&array[i]);
    }
    int Max = array[0];
    int Max_has = array[0];
    int start = 0;
    int end = 0;
    for (int i = 1; i<n ;i++)
    {
        int st_tg = start;
        if (Max_has > 0) Max_has += array[i];
        else{
            Max_has = array[i];
            st_tg = i;
        }
        if (Max < Max_has) 
        {
            Max = Max_has;
            start = st_tg;
            end = i;
        }
    }

    printf("The max array is from %d to %d with sum value is %d\n ",start,end,Max);
}
