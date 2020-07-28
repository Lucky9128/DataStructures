#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int N,dis;
        cin>>N>>dis;
        for(int i=0;i<N;i++)
        {
            int divi;
            cin>>divi;
            
            long divin =((long)divi)<<31;
            long rem = (long)dis;
            int quot =0;
            for(int i=0;i<32;i++)
            {
                rem = rem - divin;
                // cout<<std::hex<<setw(12)<<quot<<"\t"<<setw(12)<<divin<<"\t"<<setw(12)<<rem<<endl;
                if(rem<0)
                {
                    rem+=divin;
                    quot<<1;
                }
                else
                {
                    quot<<=1;
                    quot|=1;
                }
                // cout<<std::hex<<setw(12)<<quot<<"\t"<<setw(12)<<divin<<"\t"<<setw(12)<<rem<<endl;
                divin>>=1;
                // cout<<std::hex<<setw(12)<<quot<<"\t"<<setw(12)<<divin<<"\t"<<setw(12)<<rem<<endl;
                // cout<<"-------------------------------------\n";
            }   
            
            
            
            
            if(rem ==0)
            {
                cout<<"1";
            }
            else
            cout<<"0";
        }
        cout<<endl;
    }
    
    
    return 0;
}