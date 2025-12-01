// #include<bits/stdc++.h>
// using namespace std;
// #define MAX 100000

// char Xau1[MAX];
// char Xau2[MAX];

// typedef struct Result{
//     int value;
//     int start1;
//     int end1;
//     int start2;
//     int end2;
// }Result;

// void init()
// {
//     cin >> Xau1 >> Xau2;
// }

// int Max_in_three(int a, int b, int c)
// {
//     if (a > b && a > c) return a;
//     else if (b > a && b > c) return b;
//     return c;
// }

// Result Max_same_string()
// {
//     Result Res;
//     int Max_curr = 0;
//     int curr_start1 = 0;
//     int curr_start2 = 0;
//     int l1 = strlen(Xau1);
//     int l2 = strlen(Xau2);
//     int Map[l1 + 1][l2 + 1];
//     for (int i = 0; i<= l1;i++)
//     {
//         Map[i][0] = 0;
//     }
//     for (int i = 0; i<= l2;i++)
//     {
//         Map[0][i] = 0;
//     }
//     for (int i = 1; i <= l1;i++)
//     {
//         for (int j = 1; j<= l2;j++)
//         {   
//             int tg = 0;
//             bool check = false;
//             if (i == 1 || j == 1 ) check = true;
//             else if (Xau1[i-2] == Xau2[j-2]) check = true;
//             if (Xau1[i-1] == Xau2[j-1] && check) 
//             {
//                 tg = Map[i-1][j-1] + 1;
//                 Map[i][j] = Map[i-1][j-1] + 1;
//                 if (tg == 2)
//                 {
//                     curr_start1 = i-2;
//                     curr_start2 = j-2;
//                 }
//             }
//             else if (Map[i-1][j] > Map[i][j-1]) Map[i][j] = Map[i-1][j];
//             else Map[i][j] = Map[i][j-1];
//             if (tg > Max_curr)
//             {
//                 Res.start1 = curr_start1;
//                 Res.start2 = curr_start2;
//                 Res.end1= i - 1;
//                 Res.end2 = j - 1;
//                 Max_curr = tg;
//             }
//         }
//     }
//     for (int i = 0; i<=l1;i++)
//     {
//         for (int j =0 ; j<=l2;j++)
//         {
//             cout << Map[i][j] <<  ' ';
//         }
//         cout <<endl;
//     }
//     Res.value = Map[l1][l2];
//     return Res;
// }

// int main()
// {
//     init();
//     Result ans = Max_same_string();
//     cout << "Max length is : "<<ans.value<<endl;
//     cout <<"The first come from "<<ans.start1 << " and end at "<<ans.end1<<endl;
//     cout <<"The second come from "<<ans.start2 << " and end at "<<ans.end2<<endl;
//     cout << "The same sub string is : ";
//     for (int i = ans.start1; i<=ans.end1;i++)
//     {
//         cout << Xau1[i];
//     }
//     return 0;
// }
// /*
// sdhfgjdfgjhdgfjdgfjkusdabcdefghp3roihwefiuhsdkicbd
// jnsdgfukiygweiuwabcdefghsdjfvjdvkfdbfj
// */


#include<bits/stdc++.h>
using namespace std;
#define MAX 100000
char Xau1[MAX];
char Xau2[MAX];

void init()
{
    cin >> Xau1 >> Xau2;
}

int max_sub_string()
{
    int l1 = strlen(Xau1);
    int l2 = strlen(Xau2);    
    int Map[l1 +1][l2 + 1];
    for (int i = 0; i <= l1;i++)
    {
        Map[i][0] = 0 ;
    }
    for (int i = 0 ;i <= l2;i++)
    {
        Map[0][i] = 0;
    }
    for (int i = 1; i<= l1 ;i++)
    {
        for (int j = 1; j<= l2;j++)
        {
            if (Xau1[i-1] == Xau2[j-1]) Map[i][j] = Map[i-1][j-1] + 1;
            else
            {
                if (Map[i-1][j] > Map[i][j-1]) Map[i][j] = Map[i-1][j];
                else Map[i][j] = Map[i][j-1];
            }
        }
    }
    return Map[l1][l2];
}

int main()
{
    init();
    cout << max_sub_string();
    return 0;
}
