// C++ program to count all subsets with 
// given sum. 
#include <bits/stdc++.h> 
using namespace std; 
#define vvi vector<vector<int>>
#define vi vector<int>
#define itr(i,a,b) for(auto i=a;i<b;i++)
// dp[i][j] is going to store true if sum j is 
// possible with array elements from 0 to i. 
bool** dp; 

void display(const vector<int>& v) 
{ 
	for (int i = 0; i < v.size(); ++i) 
		printf("%d\t", v[i]); 
	printf("\n"); 
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




void display(bool **arr, int row, int col)
{
    
    for(int i=0;i<row;i++)
    {   
        for(int j=0;j<col;j++)
        {
            cerr<<arr[i][j]<<"\t";       
        }
        cerr<<endl;
    }
    cerr<<endl;
}
// A recursive function to print all subsets with the 
// help of dp[][]. Vector p[] stores current subset. 
void printSubsetsRec(int arr[], int i, int sum, vector<int>& p) 
{ 
    display(p);
    cout<<"Sum ->"<<sum<<" num ->"<<i<<endl;
	// If we reached end and sum is non-zero. We print 
	// p[] only if arr[0] is equal to sun OR dp[0][sum] 
	// is true. 
	if (i == 0 && sum != 0 && dp[0][sum]) 
	{
        cout<<"S1"<<endl; 
		p.push_back(arr[i]); 
		display(p); 
		return; 
	} 

	// If sum becomes 0 
	if (i == 0 && sum == 0) 
	{
        cout<<"S2"<<endl; 
		display(p); 
		return; 
	} 

	// If given sum can be achieved after ignoring 
	// current element. 
	if (dp[i-1][sum]) 
	{
        cout<<"S3"<<endl; 
		// Create a new vector to store path 
		vector<int> b = p; 
		printSubsetsRec(arr, i-1, sum, b); 
	} 

	// If given sum can be achieved after considering 
	// current element. 
	if (sum >= arr[i] && dp[i-1][sum-arr[i]]) 
	{
        cout<<"S4"<<endl; 
		p.push_back(arr[i]); 
		printSubsetsRec(arr, i-1, sum-arr[i], p); 
	} 
}



void Print(vvi vec, int sum, vi p, int i, vi set)
{
    // cout<<sum<<"\t"<<set[i-1]<<"\t->";
    // display(p);
    if(sum==0)
    {
        display(p);
        return;
    }

    if(vec[i-1][sum]==1)
    {
        vi temp=p;
        Print(vec,sum,p,i-1,set);
    }
    if(vec[i][sum]==1)
    {
        p.push_back(set[i-1]);
        Print(vec,sum-set[i-1],p,i-1,set);
        return;
    }
}

void MakeDpTable(vi vec, int sum)
{
    vi temp(sum+1,0);
    vvi vec2(vec.size()+1,temp);
    itr(i,0,vec.size()+1)
        vec2[i][0] = 1;        

    itr(i,1,vec.size()+1)
    {
        itr(j,1,sum+1)
        {
            vec2[i][j] = (vec[i-1] <= j) ? (vec2[i-1][j-vec[i-1]] || vec2[i-1][j]) : vec2[i-1][j];  
        }
    }
    vi p;
    display(vec2);
    Print(vec2,sum,p,vec.size(),vec);
}



// Prints all subsets of arr[0..n-1] with sum 0. 
void printAllSubsets(int arr[], int n, int sum) 
{ 
	if (n == 0 || sum < 0) 
	return; 

	// Sum 0 can always be achieved with 0 elements 
	dp = new bool*[n]; 
	for (int i=0; i<n; ++i) 
	{ 
		dp[i] = new bool[sum + 1]; 
		dp[i][0] = true; 
	} 

	// Sum arr[0] can be achieved with single element 
	if (arr[0] <= sum) 
	dp[0][arr[0]] = true; 

	// Fill rest of the entries in dp[][] 
	for (int i = 1; i < n; ++i) 
		for (int j = 0; j < sum + 1; ++j) 
			dp[i][j] = (arr[i] <= j) ? dp[i-1][j] || 
									dp[i-1][j-arr[i]] 
									: dp[i - 1][j]; 
	if (dp[n-1][sum] == false) 
	{ 
		printf("There are no subsets with sum %d\n", sum); 
		return; 
	} 

	// Now recursively traverse dp[][] to find all 
	// paths from dp[n-1][sum] 
    vector<int> temp(11);
    for(int i=0;i<11;i++)
    {
        temp[i]=i;
    }
    display(temp);
	vector<int> p; 
    display(dp,n,sum+1);
	printSubsetsRec(arr, n-1, sum, p); 
} 

// Driver code 
int main() 
{ 
	int arr[] = {1, 2, 2, 2, 5}; 
    vi vec = {1, 2, 2, 2, 5}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	int sum = 7; 
	// printAllSubsets(arr, n, sum); 
    MakeDpTable(vec,sum);
	return 0; 
} 
