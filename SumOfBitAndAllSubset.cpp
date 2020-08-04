#include<iostream>
#include<vector>
#include<cstdio>
#include<math.h>

#define vvi vector<vector<int>>
#define vi vector<int>

#define inf INT32_MAX

#define Min(x,y) x<y?x:y
#define Max(x,y) x<y?y:x
#define And(x,pos)   (x & 1<<pos)?1:0



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

    vi vec = {2,3,4};

/*
    1 -> 001
    2 -> 010
    3 -> 011
    4 -> 100

    Anding -> set -> value : 1+2+3+4=10
              {1,2}     -> 000      
              {1,3}     -> 001 + 10 = 11
              {1,4}     -> 000
              {2,3}     -> 010 + 11 = 13
              {2,4}     -> 000
              {3,4}     -> 000
              {1,2,3}   -> 000 
              {1,2,4}   -> 000 
              {1,3,4}   -> 000 
              {2,3,4}   -> 000 
              {1,2,3,4} -> 000    

means adding (2^0) + (2^1) + (2^0 +2^1) + (2^2) + (2^0) + (2^1) = 13
Anding numbers      1   -> 001
                    2   -> 010
                    3   -> 011
                    4   -> 100
            --------------
counting num of 1's     -> 122
recount it by 2^(#bits)-1
new count ->   133
Sum = 1*2^2 + 3*2^1 + 3*2^0 = 4+6+3 = 13
*/

    vi vec2(32,0);
    for(int i=0;i<32;i++)
    {
        for(int j=0;j<vec.size();j++)
        if(And(vec[j],i))
            vec2[i]++;
    }

    int sum=0;
    for(int i=0;i<32;i++)
    {
        if(vec2[i]>=1)
        {
            vec2[i]= pow(2,vec2[i])-1;
        }
    }
    display(vec2);
    for(int i=0;i<32;i++)
    {
        if(vec2[i]>=1)
        {
            sum+= vec2[i]*pow(2,i);
        }
    }
    cout<<sum<<endl;



    return 0;
}