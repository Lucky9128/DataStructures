#include<iostream>
#include<vector>
#define Max(x,y) x>y?x:y
#define Min(x,y) x>y?y:x

using namespace std;

template <class T>
void display(T arr)
{
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}


vector<int> min_max(vector<int> arr,int x,int y)
{
    vector<int> temp(2);
    if(y-x<=1)
    {   
        temp[0]=(Min(arr[x],arr[y]));
        temp[1]=(Max(arr[x],arr[y]));
    }
    else
    {
        int k = (x+y)/2;
        vector<int> ptr1 = min_max(arr,x,k);
        vector<int> ptr2 = min_max(arr,k+1,y);
        temp[0]=(Min(ptr1[0],ptr2[1]));
        temp[1]=(Max(ptr2[1],ptr1[1]));
    }    
    return temp;
}

int main()
{
    vector<int> arr = {10,1,9,2,8,3,7,4,5,6};
    vector<int> arr2;
    arr2 = min_max(arr,0,9);
    display(arr);
    display(arr2);
    return 0;
}