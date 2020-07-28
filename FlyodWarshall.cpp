#include<iostream>
#include<vector>
#include<iomanip>
#define vvi vector<vector<long>>
#define vi vector<long>
#define inf INT32_MAX
#define Min(x,y) x<y?x:y
using namespace std;

void display(vvi arr)
{
    
    for(int i=0;i<arr.size();i++)
    {   
        for(int j=0;j<arr[0].size();j++)
        {
            cerr<<setw(10)<<arr[i][j]<<"\t";       
        }
        cerr<<endl;
    }
    cerr<<endl;
}

int main()
{
    freopen("log.txt","w",stderr);
    int ver = 6;
    vvi nodes(ver);

    vvi edges = {{1,2,2},
                 {1,3,4},
                 {2,3,1},
                 {2,4,7},
                 {3,5,3},
                 {4,6,1},
                 {5,4,2},
                 {5,6,5}};

    for(int i=0;i<ver;i++)
    {
        vi tmp(6,inf);
        nodes[i]=tmp;
        nodes[i][i]=0;
    }


    for(int i=0;i<edges.size();i++)
    {
        nodes[edges[i][0]-1][edges[i][1]-1] = edges[i][2];
    }

    display(nodes);
    for(int i=0;i<nodes.size();i++)
    {
        for(int j=0;j<nodes.size();j++)
        {
            for(int k=0;k<nodes.size();k++)
            {
                if(i!=j)
                {
                    // cerr<<"Applying row->"<<i<<" to ->"<<j<<endl;
                    nodes[j][k] = Min(nodes[j][k],nodes[j][i] + nodes[i][k]);
                }
            }
        }
    }
    display(nodes);

    return 0;
}