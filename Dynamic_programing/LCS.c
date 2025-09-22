#include<stdio.h>
#include<stdlib.h>

int max_two(int a, int b)
{
    return (a>b)? a:b;
}
int main()
{
    int len_a;
    int len_b;
    scanf("%d %d",&len_a,&len_b);
    char* str_a = (char*)malloc(sizeof(char)*len_a);
    char* str_b = (char*)malloc(sizeof(char)*len_b);
    scanf("%s",str_a);//       buffer overflow
    scanf("%s",str_b);
    int longest = 0 ;
    int start = -1;
    int end = -1;
    // set the index and give them the num 
    int check[len_a ][len_b];
    for (int i = 0; i<len_a;i++) check[i][0] = 0;
    for (int i = 0; i< len_b;i++) check[0][i] = 0;
    for (int i = 1; i<len_a;i++)
    {
        int chall = 0;
        for (int j = 1 ; j<len_b;j++)
        {
            if (str_a[i] == str_b[j]) 
            {
                chall = 1;
                check[i][j] = check[i-1][j-1] + 1;
            }
            else if (chall == 1) check[i][j] = check[i][j-1];
            else  
            {
                check[i][j] = check[i-1][j];
            }
            if (longest < check[i][j]) longest = check[i][j];
        }
    }
    printf("The longest is %d \n",longest);
}