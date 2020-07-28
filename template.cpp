#include<iostream>
#include<vector>
#include<cstdio>

#define vvi vector<vector<int>>
#define vi vector<int>

#define inf INT32_MAX

#define Min(x,y) x<y?x:y
#define Max(x,y) x<y?y:x

using namespace std;

void display(vi vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cerr<<vec[i]<<"\t";       
    }
    cerr<<endl;
}

void display(vvi arr)
{
    
    for(int i=0;i<arr.size();i++)
    {   
        for(int j=0;j<arr[0].size();j++)
        {
            cerr<<arr[i][j]<<"\t";       
        }
        cerr<<endl;
    }
    cerr<<endl;
}



int main()
{

    freopen("log.txt","w",stderr);

    vi vec;
    vvi arr;


    for(int i=0;i<vec.size();i++)
    {
        
    }
    for(int i=0;i<arr.size();i++)
    {   
        for(int j=0;j<arr[0].size();j++)
        {
            
        }
    }

    return 0;
}