#include<iostream>
#include<vector>
#include<cstdio>

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



int main()
{

    freopen("log.txt","w",stderr);

    vi vec = {6, 3, 9, 2, 4, 10, 2, 3, 8, 1, 4, 5};
    vi vec2;
    int k=5;
    int ind=-1;
    itr(i,0,k)
    {
        if(vec[ind]<vec[i])
        {
            ind=i;
        }
    }
    cout<<ind<<endl;
    cout<<vec.size()-k+1<<endl;
    vec2.push_back(vec[ind]);  
    itr(i,1,vec.size()-k+1)
    {
        cout<<"Checking for "<<vec[i]<<" and "<<vec[i+k-1]<<endl;
        ind = (vec[ind]<vec[i+k-1])?i+k-1:ind;
        vec2.push_back(vec[ind]);  
    }
    display(vec2);
    return 0;
}