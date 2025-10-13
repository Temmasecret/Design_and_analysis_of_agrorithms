#include<stdio.h>
#define MAX 100

int res[MAX];
int check_row[MAX];
int check_pass1[2*MAX - 1];
int check_pass2[2*MAX - 1];
int n;
int count = 0;

void init(void)
{
    scanf("%d",&n);
    for (int i = 0; i<MAX;i++)
    {
        check_row[i] = 0;
    }
    int tg = 2*MAX - 1;
    for (int i = 0; i< tg;i++)
    {
        check_pass1[i] = 0;
        check_pass2[i] = 0;
    }
}

void Show_result()
{
    count++;
    printf("Toa do lan %d : ",count);
    for (int i = 0;i<n;i++)
    {
        printf("(%d , %d) ",i,res[i]);
    }
    printf("\n");
}

void Solve(int idx)
{
    if (idx == n)
    {
        return Show_result();
    }
    for (int i = 0;i<n;i++)
    {
        if (check_row[i] == 0 && check_pass1[i + idx] == 0 && check_pass2[n-i+idx-1] == 0)
        {
            check_row[i] = 1;
            check_pass1[i+idx] = 1;
            check_pass2[n - i + idx - 1] = 1;
            res[idx] = i; 
            Solve(idx + 1);
            check_row[i] = 0;
            check_pass1[i+idx] = 0;
            check_pass2[n - i + idx -1] = 0;
        }
    }
}

int main()
{   
    init();
    Solve(0);
    return 0;
}