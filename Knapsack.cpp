#include<iostream>
#include<cstdio>
#define vi vector<int>
#define vf vector<float>
#define df vector<vector<float>>
#define di vector<vector<int>>
#define Max(x,y) x<y?y:x

#include<vector>

using namespace std;
void display(vi vec)
{
    for(auto i=0;i<vec.size();i++)
    {
        cerr<<vec[i]<<"\t";
	}
    	cerr<<endl;
}
void display(vf vec)
{
    for(auto i=0;i<vec.size();i++)
    {
        cerr<<vec[i]<<"\t";
	}
    	cerr<<endl;
}
void display(di vec)
{
    for(auto i=0;i<vec.size();i++)
    {
        for(auto j=0;j<vec[i].size();j++)
            cerr<<vec[i][j]<<"\t";
        cerr<<endl; 
	}
}
void display(df vec)
{
    for(auto i=0;i<vec.size();i++)
    {
        for(auto j=0;j<vec[i].size();j++)
            cerr<<vec[i][j]<<"\t";
        cerr<<endl; 
	}
}
int main()
{
    freopen("log.txt","w",stderr);
    df wgts = {{1,1},{2,6},{5,18},{6,22},{7,28}};
    int num = 5;
    // int ttlwgts = 25;

    // vf ratio;
    // for(int i=0;i<wgts.size();i++)
    // {
    //     ratio.push_back(wgts[i][1]/wgts[i][0]);
    // }
    // display(ratio);
    int col = 15;
    int row = wgts.size()+1;
    di mat = {{0}};
    for(int i=1;i<=col;i++)
    {
        mat[0].push_back(0);
    }

    // display(mat);

    for(int i=1;i<row;i++)
    {
        cerr<<"Looking for row->"<<i<<" wgts ->"<<wgts[i-1][0]<<endl;
        mat.push_back({0});
        for(int j=1;j<=col;j++)
        {
            if(wgts[i-1][0]>j)
            {
                mat[i].push_back(mat[i-1][j]);
            }
            else
            {
                mat[i].push_back(Max(mat[i-1][j],mat[i-1][j-wgts[i-1][0]]+wgts[i-1][1]));
            }
            
        }
        display(mat);
        cerr<<"-------------------------------------------------------------------------\n";
    }
    display(mat);





    return 0;
}