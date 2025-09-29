#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;

struct ptu
{
    int d1;
    int d2;
    int trongso;
};
ptu Ptu[100];
int socanh, sodinh;

void init()
{
    fstream f;
    f.open("input.txt", ios :: in);
    if ( !f ) cout<<"loi";
    f >> socanh;
    f >> sodinh;
    int i;
    for ( i = 0; i < socanh; i++)
    {
        f >> Ptu[i].d1;
        f >> Ptu[i].d2;
        f >> Ptu[i].trongso;
    }
}
void hd()
{
    ptu tem;
    int i,j;
    for ( i = 0; i < socanh-1 ; i++) // sắp xếp các cạnh theo trọng số tăng dần
    {
        for ( j = i+1 ; j < socanh; j++)
        {
            if ( Ptu[i].trongso > Ptu[j].trongso)
            {
                tem = Ptu[j];
                Ptu[j] = Ptu[i];
                Ptu[i] = tem;
            }
        }
    }
    int daxet[100] = {0}, sum = 0; // Khởi tạo tất cả phần tử bằng 0

    cout<<"\n Khung cay theo thuat toan KrusKal la: \n ";
    cout<<"\t"<<Ptu[0].d1<<" - "<<Ptu[0].d2<<"\t:Trong so: "<<Ptu[0].trongso;
    i = 1; sum+=Ptu[0].trongso;
    /* vì đã sắp xếp nên theo thuật toán kruskal lấy cạnh đầu tiên để bắt đầu, khi này 2 đỉnh có đã xét = 1, khi bắt đầu
    lấy cạnh tiếp theo min trong những cạnh chưa đưa vào khung cây, vì phải đảm bảo khung cây không tạo thành chu trình nên trong cạnh vừa chọn 
    bắt buộc phải có  1 đỉnh chưa được xétxét
    */
    daxet[ Ptu[0].d1 ] = 1; daxet[ Ptu[0].d2 ] = 1;
    int count = 2;// dem so dinh da xetxet
    while (  count <= sodinh && i < socanh)
    {
        if ( daxet[Ptu[i].d1] == 1 && daxet[Ptu[i].d2] == 1)
            i++;
        else if(  ( daxet[Ptu[i].d1] == 1 && daxet[Ptu[i].d2] == 0 ) || ( daxet[Ptu[i].d1] == 0 && daxet[Ptu[i].d2] == 0 ) || ( daxet[Ptu[i].d2] == 1 && daxet[Ptu[i].d1] == 0 ) )
        {
            cout<<"\n\t"<<Ptu[i].d1<<" - "<<Ptu[i].d2<<"\t:Trong so: "<<Ptu[i].trongso;
            sum+=Ptu[i].trongso;
            if ( daxet[Ptu[i].d1] == 0 ) 
            {
                daxet[Ptu[i].d1] = 1;
                count++;
            }
            if ( daxet[Ptu[i].d2] == 0 ) 
            {
                daxet[Ptu[i].d2] = 1;
                count++;
            }
            i++;
        }
    }
}
int main()
{
    init();
    hd();
}