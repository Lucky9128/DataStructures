#include<iostream>
#include<vector>
#include<cstdio>

#define vvi vector<vector<int>>
#define vi vector<int>

#define inf INT32_MAX

#define Min(x,y) x<y?x:y
#define Max(x,y) x<y?y:x

using namespace std;

void display(vvi arr)
{
    
    for(int i=0;i<arr.size();i++)
    {   
        for(int j=0;j<arr[0].size();j++)
        {
            cout<<arr[i][j]<<"\t";       
        }
        cout<<endl;
    }
    cerr<<endl;
}

void swap(vi &a1,vi &a2)
{
    vi temp = a1;
    a1 = a2;
    a2 = temp;
}

int partition(vvi &A, int low, int high, int ind)
{
    int pvt = A[high][ind];
    int i=low-1,j=high;

    for(int j=low;j<high;j++)
    {
        // cerr<<"p->low ->"<<j<<" high ->"<<high<<" pivot is->"<<pvt<<endl;
        if(A[j][ind]<pvt)
        {
            i++;
            swap(A[i],A[j]);
        }
    }
    swap(A[i+1],A[high]);
    // cerr<<i+1<<endl;
    // display(A);
    return i+1;
}



void quick(vvi &vec, int low, int high, int ind)
{
    if(low<high)
    {
        // display(vec);
        int pivot = partition(vec,low,high,ind);
        // cerr<<"low ->"<<low<<" high ->"<<high<<" pivot is->"<<pivot<<endl;
        quick(vec,low,pivot-1,ind);
        quick(vec,pivot+1,high,ind);
    }
}

void calSUm(vvi &arr)
{
    arr.erase(arr.begin(),arr.begin()+2);
}

int main()
{

    freopen("log.txt","w",stderr);

    // vi vec;
    vvi arr = {{2,4},{4,9},{1,8},{1,9},{3,12}};
    // vvi arr = {5,4,2,3,6,8,7};
    // vvi arr = {{334,1000},{334,1000},{334,1000}};
    // quick(arr,0,arr.size()-1,0);
    calSUm(arr);
    display(arr);
    // long cnt=0;
    // for(int i=0;i<arr.size();i++)
    // {
    //     if(arr[i][1]>=cnt+arr[i][0])
    //     {
    //         cnt+=arr[i][0];
    //         // cout<<cnt<<endl;
    //     }
    //     else
    //     {
    //         cnt=-1;
    //         break;
    //     }
        
    // }
    // if(cnt==-1)
    //     cout<<"No\n";
    // else
    //     cout<<"Yes\n";
    return 0;
}