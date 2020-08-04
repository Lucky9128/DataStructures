#include<iostream>
#include<vector>
#include<cstdio>
#include<math.h>
#define vvi vector<vector<int>>
#define vi vector<int>
#define itr(i,a,b) for(auto i=a;i<b;i++)


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

/*
1st and last digit will repeat for size of array
other elements will repeat for 2*size_of_arr - 2

*/

int main()
{

    freopen("log.txt","w",stderr);

    vi vec = {2,4};
    long long prdt=1;

    if(vec.size()==1)
    {
        prdt=vec[0];
    }
    else
    {
        prdt *=  pow(vec[0],vec.size());
        prdt *=  pow(vec.back(),vec.size());
        int k = vec.size()*2-2;
        itr(i,1,vec.size()-1)
        {
            prdt *= pow(vec[i],k);
        }
    }
    cout<<prdt<<endl;
    return 0;
}