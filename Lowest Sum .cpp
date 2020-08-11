#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define vvi vector<vector<ll>>
#define vi vector<ll>
#define um unordered_map<ll,ll>
#define ms multiset<ll>
#define itr(i,a,b) for(auto i=a;i<b;i++)
#define ittr(i,a) for(auto i=a.begin();i!=a.end();i++)


#define inf INT32_MAX

#define Min(x,y) x<y?x:y
#define Max(x,y) x<y?y:x
using namespace std;

void display(ms arr)
{
    ittr(i,arr)
        cerr<<*i<<"\n";
    cerr<<endl;
}


int main()
{
    freopen("log.txt","w",stderr);
    vi v1 = {386 ,34 ,500 ,315 ,392 ,379 ,483 ,306 ,440 ,27, 107 ,76 ,123 ,375};
    vi v2 = {58 ,90, 54 ,54 ,100 ,97, 91, 74 ,88 ,63, 90, 73 ,69, 81};
    // ll k =20000;
    // itr(i,0,k)
    //     v1.push_back(pow(10,10)*i+1);
    // itr(i,k,2*k)
    //     v2.push_back(pow(10,9)*i+1);
        clock_t t1 = clock();
        vi qry = {2,5,10,25};
        int max  = -1;
        itr(i,0,qry.size())
        {
            if(qry[i]>max)
            {
                max = qry[i];
            }
        }     
        int k = v1.size();
        ms s1,s2,sum;
        if(max>=k)
            max = k-1;
        itr(i,0,max+1)
            s1.insert(v1[i]);
        itr(i,0,max+1)
            s2.insert(v2[i]);
        display(s1);
        cerr<<"--------------------------\n";
        display(s2);
        cerr<<"--------------------------\n";
        ittr(it1,s1)
        {
            ittr(it2,s2)
            {
                sum.insert(*it1+*it2);
            }
        }
        display(sum);
        vi fnl(sum.begin(),sum.end());
        itr(i,0,qry.size())
        {
            cout<<fnl[qry[i]-1]<<endl;
        }
    clock_t t2 = clock();
    double duf = (double)(t2-t1)/CLOCKS_PER_SEC;
    cerr<<duf<<endl;
    return 0;
}


/*
vi Merge(vi v1,vi v2)
{
    int i=0,j=0;
    vi vec(v1.size()+v2.size());
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
            j++;
        }
    }
    return vec;
}

vi DobMergeSort(vi v3,vi v4)
{
    if(v3.size()<2)
    {
        vi vec;
        itr(i,0,v4.size())
        {
            vec.push_back(v3[0]+v4[i]);
        }
        return vec;
    }
    if(v4.size()<2)
    {
        vi vec;
        itr(i,0,v3.size())
        {
            vec.push_back(v4[0]+v3[i]);
        }
        return vec;
    }
    // cerr<<"Applying merge on : "<<endl;
    // display(v3);
    // display(v4);
    int q =( v3.size()+1)/2;
    int j =( v4.size()+1)/2;
    vi left1(v3.begin(),v3.begin()+q);
    vi rgt1(v3.begin()+q,v3.end());
    vi left4(v4.begin(),v4.begin()+j);
    vi rgt4(v4.begin()+j,v4.end());
    vi res1 = DobMergeSort(left1,left4);
    vi res2 = DobMergeSort(rgt1,rgt4);
    vi res11 = DobMergeSort(left1,rgt4);
    vi res21 = DobMergeSort(rgt1,left4);
    vi res3 = Merge(res1,res2);
    // cerr<<"After merging first half :"<<endl;
    // display(res3);
    vi res4 = Merge(res11,res21);
    // cerr<<"After merging other half :"<<endl;
    // display(res4);
    return Merge(res3,res4);
}
int main()
{
    freopen("log.txt","w",stderr);
    vi v1,v2;
    int k =1000;
    itr(i,0,k)
        v1.push_back(i+1);
    itr(i,k,2*k)
        v2.push_back(i+1);


    vi qry = {3,7,8,2};

    ms s1,s2;
    ittr(i,v1)
        s1.insert(*i);
    ittr(i,v2)
        s2.insert(*i);
    

    vi v3(s1.begin(),s1.end());
    vi v4(s2.begin(),s2.end());

    // display(v3);
    // display(v4);
    clock_t t1 = clock();
    // vi vec = DobMergeSort(v3,v4);
    clock_t t2 = clock();
    double duf = (double)(t2-t1)/CLOCKS_PER_SEC;
    // cout<<duf<<endl;
    // display(vec);
    ms sum;    
    t1 = clock();
    ittr(it1,s1)
    {
        ittr(it2,s2)
        {
            sum.insert(*it1+*it2);
        }
    }    
    t2 = clock();
    duf = (double)(t2-t1)/CLOCKS_PER_SEC;
    // cout<<std::dec<<duf<<endl;
    printf("%lf\n",duf);
    return 0;
}*/