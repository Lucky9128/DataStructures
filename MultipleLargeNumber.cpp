#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int k;

int GetMinBase(int x, int y)
{
    int i =-1;
    while(x%10!=0)
    {
        x/=10;
        i++;
    }
    int j=-1;
    while(y%10!=0)
    {
        y/=10;
        j++;
    }
    // cout<<i<<"\t"<<j<<endl;
    return (i<j)?i:j;
}

void SplitToBase(int x, int base, vector<int> *res)
{
    res->push_back(x/pow(10,base));
    res->push_back(x%(int)pow(10,base));
}



int karasuba(int x, int y)
{
    cout<<"karasuba : x = "<<x<<", y = "<<y<<endl;
    if(x<=10 || y<=10)
        return x*y;
    cin>>k;
    int minBase = GetMinBase(x,y);
    cout<<"base : "<<minBase<<endl;
    vector<int> opr1;
    SplitToBase(x,minBase,&opr1);
    vector<int> opr2;
    SplitToBase(y,minBase,&opr2);
    cout<<"New numbers : x0 = "<<opr1[1]<<", x1 = "<<opr1[0]<<", y0 = "<<opr2[1]<<", y1 = "<<opr2[0]<<endl;
        cin>>k;

    int z2 = karasuba(opr1[0],opr2[0]);
    int z0 = karasuba(opr1[1],opr2[1]);
    int z1 = karasuba((opr1[0]+opr1[1]),(opr2[1]+opr2[0]))-z2-z0;
    cout<<"z0 = "<<z0<<" z1 = "<<z1<<" z2 = "<<z2<<endl; 
    return (z2*(int)pow(10,minBase*2) + z1*(int)pow(10,minBase) + z0 );
}



int main()
{
    cout<<karasuba(345,435)<<endl;
    cout<<(345*435)<<endl;
    return 0;
}