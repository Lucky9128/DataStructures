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


    string str1 = "AGGTAB";
    string str2 = "GXTXAYB";

    vi temp(str1.length()+1,0);
    vvi vec(str2.length()+1,temp);

    for(int i=1;i<str2.length()+1;i++)
    {
        for(int j=1;j<str1.length()+1;j++)
        {
            cerr<<str2[i-1]<<"->"<<str1[j-1]<<endl;
            if(str2[i-1]==str1[j-1])
            {
                vec[i][j] = vec[i-1][j-1]+1;
            }
            else
            {
                vec[i][j] = Max(vec[i-1][j],vec[i][j-1]);
            }
            
        }
    display(vec);
    cerr<<"---------------------------------------------------------\n";
    }

    return 0;
}