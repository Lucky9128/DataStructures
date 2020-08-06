#include<iostream>
#include<vector>
#include<cstdio>
#include<algorithm>
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

// int isMod(int a, int b)
// {
//     if(a==0||b==0)
//         return 0;

//     if(a%b>1)
//     {
//         int k;
//         cout<<"Mod of "<<a<<"\t"<<b<<endl;
//         // cin>>k;
//         return isMod(b,a%b);
//     }
//     else
//         return a%b;
// }

// int CntMod(vi vec, int frm, int of)
// {
//     int cnt=0;
//     itr(i,frm,vec.size())
//     {
//         if(isMod(vec[i],vec[of]))
//         {
//             cout<<"\t Checking with "<<vec[of]<<" to "<<vec[i]<<" ret : "<<1<<endl;
//             cnt++;
//         }
//     }
//     return cnt;
// }




// int main()
// {

//     freopen("log.txt","w",stderr);

//     // vi vec = {7,3,5,2};
//     // vi vec = {3,4,8,16};
//     vi vec = {6,10,15};
//     // cout<<isMod(7,5)<<endl;
//     int ttl=0;
//     itr(i,0,vec.size()-1)
//     {
//         int cnt = CntMod(vec,i+1,i);
//         cout<<"Calling for mod "<<vec[i]<<" : "<<cnt<<endl;
//         if(cnt == vec.size()-i-1)
//         {
//             ttl += (1<<cnt) - 1;
//             cout<<"same : "<<ttl<<" : "<<cnt<<" : "<<(1<<cnt)<<endl;
//         }
//         else if(cnt>0)
//         {
//             int sub = vec.size() - cnt - i - 1;
//             sub = 1<<sub;
//             ttl += sub*(1<<cnt - 1);
//             cout<<"Nots : "<<cnt<<endl;
//         }
//         else
//         {
//             cout<<"Re arrange"<<endl;
//             itr(j,i+1,vec.size())
//                 if(vec[i]!=0)
//                 vec[j] = vec[j]%vec[i];
//             display(vec);
//         }
        
        
//     }

//     cout<<ttl<<endl;
//     return 0;
// }

///////////////////////////////////////previous solution didn't work/////////////////////////////////////////
/*
                                                        2357
                                        357                                2357
                                57               357             257                    2357

*/
vi vec;
vvi tab;
int n;
int CalGame(int ind, int gcd)
{

    if(ind == n)
    {
        if(gcd==1)
            return 1;
        else
            return 0;
    }

    if(tab[ind][gcd]!=-1)
    {
        return tab[ind][gcd];
    }

    return tab[ind][gcd] = CalGame(ind+1,gcd) + CalGame(ind+1, __gcd(gcd,vec[ind]));

}



int main()
{
    // vec = {2,3,5,7};
    vec = {6,10,15};
    n=vec.size();
    vvi temp(n,vi(100001,-1));
    tab = temp;
    cout<<CalGame(0,0)<<endl;

}