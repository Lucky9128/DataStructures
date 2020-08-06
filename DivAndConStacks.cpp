#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define vvi vector<vector<int>>
#define vi vector<int>
#define um unordered_map<int,int>
#define itr(i,a,b) for(auto i=a;i<b;i++)


#define inf INT32_MAX

#define Min(x,y) x<y?x:y
#define Max(x,y) x<y?y:x
using namespace std;

int indRet(vi vec, ll num)
{
    
    if(vec.size()==0)
        return -1;
    if(vec.size()==1)
    {
        if(vec[0]>num)
            return 0;
        else
            return -1;
    }
    int high = vec.size();
    int low = 0;
    int pre;
    int curr = (low+high)/2;
    while(1)
    {
        // cerr<<curr<<"\t"<<low<<"\t"<<high<<endl;
        if(vec[curr]<num)
            low = curr;
        else if(vec[curr]>num)
            high = curr;
        else
        {
            break;
        }
        pre = (low + high)/2;
        if(pre==curr)
        {
            break;
        }
        curr = pre;
    }
    if(curr == 0)
    {
        // cerr<<"Curr = 0 : "<<(vec[curr]<=num)<<endl;
        if(vec[curr]<=num)
            return curr+1;
        else
        {
            return curr;
        }
        
    }
    if(curr == vec.size()-1)
    {
        if(vec[curr]<=num)
            return -1;
    }
    return curr+1;
}

void display(vi vec)
{
    for(int i=0;i<vec.size();i++)
    {
        cerr<<vec[i]<<"\t";       
    }
    cerr<<endl;
}

void display(um vec)
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

void myFun2(vi &vec,int num)
{
    int low = 0, high = vec.size();
    int mid  = (low+high)/2;
    int pre;
    while(low<high)
    {
        cerr<<low<<"\t"<<high<<"\t"<<mid<<endl;
        if(num>vec[mid])
        {
            low = mid;
        }
        else if(num<vec[mid])
        {
            high = mid;
        }
        else
        {
            vec[mid+1] = num;       
            return;
        }
        pre = (low+high)/2;
        if(pre==mid)
        {  
            vec[mid+1] = num;   
            return;       
        }
        mid = pre;
    }
    vec[low]=num;
    return;


}

void myFunc(vvi vec, um &arr, int i)
{
    // cerr<<"For i "<<i<<endl;
    if(i==vec.size())
        return;
    if(vec[i][1]==1)
    {
        myFunc(vec,arr,i+1);
        return;
    }
    arr[vec[i][0]]=1;
    int curr = vec[i][0];
    itr(j,i+1,vec.size())
    {
        // cerr<<"Curr : "<<curr<<endl;
        if(curr>vec[j][0] && vec[j][1]!=1)
        {
            arr[arr.size()-1] = vec[j][0];
            vec[j][1] = 1;
            curr = vec[j][0];
        }
        // cerr<<"next : "<<curr<<endl;
    }
    // display(arr);
    myFunc(vec,arr,i+1);
    return;
}


int main()
{
    freopen("log.txt","w",stderr);
    // vi vec = {3,4,5,1,1,2};
    vi vec = {3,5,7,9,1};
    // vi vec = {3,2,9,5,2,9,4,14,7,10};
    // vi vec = {14,5,13,19,17,10,18,12};
    vvi temp;
    itr(i,0,vec.size())
    {
        temp.push_back({vec[i],0});
    }
    vi vec2(vec.size(),inf);
    itr(i,0,vec.size())
    { 
        cerr<<vec[i]<<endl;
        myFun2(vec2,vec[i]);
        display(vec2);
        cerr<<"---------------------------------------\n";
    }
    cerr<<vec2.size()<<endl;
    display(vec2);
    return 0;
}