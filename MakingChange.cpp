#include<iostream>
#include<string>
#include<iomanip>
#define Min(x,y) x>y?y:x
#include<vector>
#include<time.h>
#include<math.h>

using namespace std;


void display(vector<vector<int>> arr)
{
    cout<<setw(5)<<0<<" |\t";
    for(int i=0;i< arr[0].size() ; i++)
        cout<<setw(5)<<i<<"\t";
    cout<<endl;
    cout<<"-----------------------------------------------------------------------------------------------------------------------------------------\n";
    for(int j=0;j<arr.size();j++)
    {
        cout<<setw(5)<<j<<" |\t";
        for(int i=0;i<arr[j].size();i++)
            std::cout<<setw(5)<<arr[j][i]<<"\t";
        std::cout<<endl;
    }
}
void display(vector<int> arr)
{
    // for(int j=0;j<arr.size();j++)
    // {
        for(int i=0;i<arr.size();i++)
            std::cout<<arr[i]<<"\t";
        std::cout<<endl;
    // }+
}


int NumOfCoins(int amt, vector<int> coins)
{
    vector<vector<int>> vec;
    vec.push_back({0});
    for(int j=1;j<=amt;j++)
    {
        if(j%coins[0]==0)
            vec[0].push_back(j/coins[0]);
        else
            vec[0].push_back(-1);
    }
    for(int i=1;i<coins.size();i++)
    {
        vec.push_back({0});
        for(int j=1;j<=amt;j++)
        {
            if(coins[i]>j)
                vec[i].push_back(vec[i-1][j]);
            else
            {
                if(vec[i][j-coins[i]]==-1)
                {
                    if(vec[i-1][j]==-1)
                        vec[i].push_back(-1);
                    else
                    {
                        vec[i].push_back(vec[i-1][j]);
                    }
                }
                else
                {
                    if(vec[i-1][j]==-1)
                        vec[i].push_back(1 + vec[i][j-coins[i]]);
                    else
                    {
                        vec[i].push_back(Min( vec[i-1][j] ,  1 + vec[i][j-coins[i]]  ));
                    }
                }
                
            }
            
        }
    }
    // display(vec);
    return   vec[coins.size()-1][amt];
}
int main()
{
    int k = 41;
    vector<int> arr = {2,5};
    // vector<vector<int>> vec = {{0,2,-1,-1,-1},{2,0,2,-1,-1},{-1,2,0,3,-1},{-1,-1,3,0,2},{-1,-1,-1,2,0}};
    // int nodes = vec.size();

    // vector<int> res;
    // res = Makecircle(vec,5,4,nodes);
    // display(res);
    // for(int i=0;i<nodes;i++)
    // {
    //     for(int j=0;j<nodes;j++)
    //     {
    //         for(int k=0;k<nodes;k++)
    //         {
    //             if(j!=i && vec[i][k]!=-1 && vec[j][i]!=-1)
    //             {
    //                 if(vec[j][k]==-1  || (vec[j][k]> vec[j][i]+vec[i][k] ) )
    //                 {
    //                     vec[j][k] = vec[j][i]+vec[i][k];
    //                 }
    //             }


    //         }
    //     }
    // }
    // display(vec);
    std::cout<<NumOfCoins(k,arr)<<endl;
    return 0;
}