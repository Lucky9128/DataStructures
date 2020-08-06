#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define vvi vector<vector<ll>>
#define vi vector<ll>
#define um unordered_map<ll,ll>
#define itr(i,a,b) for(auto i=a;i<b;i++)
#define ittr(i,a) for(auto i=a.begin();i!=a.end();i++)


#define inf INT32_MAX

#define Min(x,y) x<y?x:y
#define Max(x,y) x<y?y:x
using namespace std;


int main()
{
    int sq[2] = {0,0};
    int low = 0,high=1000;
    int mid,cur;
    while(1)
    {
        mid = (low + high)/2;
        cout<<"? "<<mid<<" 0"<<endl;
        fflush(stdout);
        string s;
        cin>>s;
        if(s == "YES")
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
        cur = (low+high)/2;
        if(cur==mid)
        {
            sq[1] = mid;
            break;
        }
        mid = cur;
    }
    
    low=sq[1];
    high = 1000;
    
    // while(1)
    // {
    //     mid = (low + high)/2;
    //     cout<<"? "<<mid<<" 0"<<endl;
    //     fflush(stdout);
    //     string s;
    //     cin>>s;
    //     if(s != "YES")
    //     {
    //         low = mid;
    //     }
    //     else
    //     {
    //         high = mid;
    //     }
    //     cur = (low+high)/2;
    //     if(cur==mid)
    //     {
    //         sq[0] = mid;
    //         break;
    //     }
    //     mid = cur;
    // }
    
    int y = 2*sq[1];
    // low = sq[1];
    // high = 1000;
    int tri[3]={0,0,0};
    while(1)
    {
        mid  = (low+high)/2;
        cout<<"? "<<mid<<" "<<y<<endl;
        fflush(stdout);
        string s;
        cin>>s;
        if(s == "YES")
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
        cur = (low+high)/2;
        if(cur==mid)
        {
            tri[2] = mid;
            break;
        }
        mid = cur;
    }
    
    // low = -1000;
    // high = sq[0];
    
    // while(1)
    // {
    //     mid = (low + high)/2;
    //     cout<<"? "<<mid<<" "<<y<<endl;
    //     fflush(stdout);
    //     string s;
    //     cin>>s;
    //     if(s != "YES")
    //     {
    //         low = mid;
    //     }
    //     else
    //     {
    //         high = mid;
    //     }
    //     cur = (low+high)/2;
    //     if(cur==mid)
    //     {
    //         tri[1] = mid;
    //         break;
    //     }
    //     mid = cur;
    // }
    
    // int x = (abs(tri[2])+abs(tri[1]))/2;
    low = y;
    high =1000;
    while(1)
    {
        mid  = (low+high)/2;
        cout<<"? 0 "<<mid<<endl;
        fflush(stdout);
        string s;
        cin>>s;
        if(s == "YES")
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
        cur = (low+high)/2;
        if(cur==mid)
        {
            tri[0] = mid;
            break;
        }
        mid = cur;
    }
    
    ll sqsum= y*y;
    ll trisum = tri[2] * (tri[0] - y);
    sqsum += trisum;
    
    cout<<"! "<<sqsum<<endl;
    
    
    
    return 0;
}