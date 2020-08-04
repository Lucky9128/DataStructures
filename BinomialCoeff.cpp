#include<iostream>
#include<string>
#include<vector>
#include<time.h>
using namespace std;
long cnt=0;

int Coff(int n, int k)
{
    cnt++;
    if(k==0 || k==n)
        return 1;
    else
    {
        return Coff(n-1,k-1)+Coff(n-1,k);
    }
    
}


int DynaCoff(int n, int k)
{
    if(k > n/2)
    {
        k = n - k;
    }
    cout<<"New k : "<<k<<endl;


    int arr[k+1][n+1];
    for(int i=0;i<=n;i++)
    {
        arr[0][i]=1;
    }
    for(int i=1;i<=k;i++)
    {
        arr[i][0]=0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=k;j++)
        {
            int k = arr[j-1][i-1];
            k += arr[j][i-1];
            arr[j][i] =k;
        }
    }
    return arr[k][n];
}



int main(int arg, char *argv[])
{

    // cout<<Coff(atoi(argv[1]),atoi(argv[2]))<<endl;
    // cout<<DynaCoff(atoi(argv[1]),atoi(argv[2]))<<endl;

    int n = 100;
    int k = n/2;
    time_t a1 = clock();

    // cout<<Coff(n,k)<<endl;
    time_t a2 = clock();
    cout<<DynaCoff(n,k)<<endl;
    time_t a3 = clock();

    // double d1 = (double)(a2-a1)/CLOCKS_PER_SEC;
    double d2 = (double)(a3-a2)/CLOCKS_PER_SEC;

    // printf("%lf\n",d1);
    printf("%lf\n",d2);

    // cout<<d1<<endl;
    // cout<<d2<<endl;

    cout<<cnt<<endl;
    return 0;
}