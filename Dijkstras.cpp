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
        for(int j=0;j<arr[i].size();j++)
        {
            cerr<<arr[i][j]<<"\t";       
        }
        cerr<<endl;
    }
    cerr<<endl;
}


vi::iterator findMinItr(vvi vec)
{
    vvi::iterator min = vec.begin();
    vvi::iterator it = min;
    for(;it!=vec.end();it++)
    {
        if(*min > *it)
            *min = *it;
    }
    *it = inf;
    return it;
}
int findMinInd(vvi vec, int indx)
{
    int num=0,i=0;
    for(; i<vec[indx].size();i++)
    {
        if(i!=indx)
        {
            if(vec[indx][num] > vec[indx][i])
                num = i;
        }
    }
    return i;
}

int main()
{

    freopen("log.txt","w",stderr);

    int ver = 6,src=1;
    vvi nodes(ver);
    vvi edges = {{1,2,2},
                 {1,3,4},
                 {2,3,1},
                 {2,4,7},
                 {3,5,3},
                 {4,6,1},
                 {5,4,2},
                 {5,6,5}};

    vvi Notvisited(ver);

    for(int i=0;i<ver;i++)
    {
        Notvisited[i]= {i+1,inf};
    }
    Notvisited[src-1][1] = 0;
    display(Notvisited);

    cerr<< findMinItr(Notvisited);


    return 0;
}