#include<iostream>
using namespace  std;


template <class T>
T expoent(T x, T n)
{
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    else if(n%2==0)
    {
        T a = expoent(x,n/2);
        return a*a;
    }
    else
    {
        T a = expoent(x,n-1);
        return x*a;
    }
    
}

int main()
{  
    for(long i=0;i<60;i++)
        cout<<i<<"\t"<<expoent(i,(long)10)<<endl;
    return 0;
}