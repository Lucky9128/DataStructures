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

int cnt=0;


void display(vi arr)
{
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}

void Merge(vi &vec, vi v1, vi v2)
{
    int i=0,j=0;
    while(i<v1.size() || j<v2.size())
    {
        if(i == v1.size())
        {
            vec[i+j] = v2[j];
            j++;   
        }
        else if(j == v2.size())
        {
            vec[i+j] = v1[i];
            i++;
        }
        else if(v1[i]<=v2[j])
        {
            vec[i+j] = v1[i];
            i++;
        }
        else
        {
            vec[i+j] = v2[j];
            cnt += v1.size() - i;
            j++;
        }
    }
    return;
}


void MergeSort(vi &vec)
{
    //cerr<<"Merge Sort called at :"<<endl;
    // display(vec);

    if(vec.size()<2)
        return;
    int q = (vec.size()+1)/2;

    vi v1(vec.begin(),vec.begin()+q);
    vi v2(vec.begin()+q,vec.end());
    MergeSort(v1);
    MergeSort(v2);
    Merge(vec,v1,v2);
    //cerr<<"After Merging : "<<endl;
    // display(vec);
    //cerr<<"Cnt value : "<<cnt<<endl;
    return;

}


int main()
{
    freopen("log.txt","w",stderr);
    // vi vec = {4,6,7,8,1,2,3,5};
    vi vec = {29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    MergeSort(vec);
    cout<<cnt<<endl;
    // string str = "Lucky";
    // if(str == "Luck")
    //     cout<<"No"<<endl;
    // else
    // {
    //     cout<<"Yes"<<endl;
    // }
    

    return 0;
}