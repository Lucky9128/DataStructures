#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back

// g++ -std=c++17 -Wshadow -Wall -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG -o 
ll dp[61][10005];
int n;
const int nax=61;
int a[nax];
ll recursive_function(int idx,int gcd){
cout<<" rec_func "<<idx<<"\t"<<gcd<<endl;
 if(idx==n){
    cout<<"ind == n and gcd = "<<gcd<<endl;
  if(gcd==1)return 1;
  else return 0;
 }
 if(dp[idx][gcd]!=-1)
 {
     cout<<"dp ind gcd !=-1"<<endl;
    return dp[idx][gcd];
 }
 return dp[idx][gcd]=recursive_function(idx+1,gcd)+recursive_function(idx+1,__gcd(gcd,a[idx]));
}
int main(){
 int t;
 cin>>t;
 while(t--){
  cin>>n;
  memset(dp,-1,sizeof(dp));
  for(int i=0;i<n;i++){
   cin>>a[i];
  }
  ll ans=0;
//   for(int i=1;i<=n;i++)
//    ans+=recursive_function(i+1,a[i]);
  ans=recursive_function(0,0);
  cout<<ans<<"\n";
 }
 return 0;
}
