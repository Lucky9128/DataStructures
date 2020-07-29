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

    vi vec = {10, 22, 9, 33, 21, 50, 41, 60};
    // vi vec = {1,2,3,4,5,6};
    vi lrnt(vec.size(),1);

    for(int i=1;i<vec.size();i++)
    {
        for(int j=i-1;j>=0;j--)
        {
            if(vec[j]<=vec[i])
            {
                lrnt[i]= Max( lrnt[i], lrnt[j]+1 );
            }
        }
        display(lrnt);
        cerr<<"--------------------------------------------\n";
    }
    return 0;
}