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


int checkCycl(vvi Graph, vi vec, int pre, int node)
{
    for(int i=0;i<Graph[node].size();i++)
    {
        // cerr<<"\t\tChecking for "<<i<< " on "<<node<<endl;
        if( i!=node && i!= pre)
        {
            if(Graph[node][i]>=1)
            {
                // cerr<<"\t\tGoing from "<<node<<" to ->"<<i<<endl;
                if(vec[i]==1)
                    return 1;
                else 
                {
                    vec[i]=1;
                    if(checkCycl(Graph,vec,node,i))
                    {

                        // cerr<<"Return "<<i<<"->"<<1<<endl;
                        return 1;
                    }
                    else
                    {
                        // cerr<<"Return "<<i<<"->"<<0<<endl;
                        vec[i]=1;
                    }
                                
                            }
                
            }
        }
    }
    return 0;
}

int Cycle(vvi Graph)
{   
    vi vec(Graph.size(),0);
    for(int i=0;i<Graph.size();i++)
    {
        vec[i]=1;
        cerr<<"Going for root node->"<<i<<endl;
        if(checkCycl(Graph,vec,i,i))
        {

            cerr<<"Return "<<i<<"->"<<1<<endl;
            return 1;
        }
        else
        {
            cerr<<"Return "<<i<<"->"<<0<<endl;
            vec[i]=0;
        }
        
    }
    return 0;
}


int main()
{

    freopen("log.txt","w",stderr);

    vi vec;
    vvi arr;

    int NumofNodes = 9;
    vvi edges = {{0,1,4},
                 {0,7,8},
                 {1,7,11},
                 {1,2,8},
                 {2,3,7},
                 {2,8,2},
                 {2,5,4},
                 {7,8,7},
                 {7,6,1},
                 {8,6,6},
                 {6,5,2},
                 {3,5,14},
                 {3,4,9},
                 {5,4,10}};
    vi temp(NumofNodes,0);
    vvi Graph(NumofNodes,temp);
    quick(edges,0,edges.size()-1,2);
    // for(int i=0;i<edges.size();i++)
    // {
    //     Graph[edges[i][0]][edges[i][1]] = edges[i][2];
    //     Graph[edges[i][1]][edges[i][0]] = edges[i][2];
    // }
    // display(Graph);
    // cerr<<Cycle(Graph)<<endl;
    int i =edges.size()-1;
    for(int i=0;i<edges.size();i++)
    {   

        Graph[edges[i][0]][edges[i][1]] = edges[i][2];
        Graph[edges[i][1]][edges[i][0]] = edges[i][2];

        if(Cycle(Graph))
        {
            Graph[edges[i][0]][edges[i][1]] = 0;
            Graph[edges[i][1]][edges[i][0]] = 0;
        }
    }

    display(Graph);
    return 0;
}