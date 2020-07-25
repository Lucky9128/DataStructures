#include<iostream>
#include<vector>

using namespace std;

void display(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}

vector<int> merge(vector<int> &arr1, vector<int>&arr2)
{
    vector<int> temp;
    int a1=0,a2=0;
    while(a1<arr1.size() && a2<arr2.size())
    {
        if(arr1[a1]<arr2[a2])
        {
            temp.push_back(arr1[a1++]);
        }
        else
        {
            temp.push_back(arr2[a2++]);
        }
    }
    while(a1<arr1.size())
        temp.push_back(arr1[a1++]); 
    while(a2<arr2.size())
        temp.push_back(arr2[a2++]);
    return temp;
}

vector<int> mergeSort(vector<int> arr, int low, int high)
{
    // cout<<"Mergesort rec low : "<<low<<" high : "<<high<<endl;
    vector<int> a1;
    if(low<high)
    {
        int mid = (low+high)/2;
        // int k;
        // cin>>k;
        // cout<<"Calling mergesort : "<<low<<" to "<<mid<<endl;
        vector<int> a2 = mergeSort(arr,low,mid);
        // display(a2);
        // cout<<"Calling mergesort : "<<mid+1<<" to "<<high<<endl;
        vector<int> a3 = mergeSort(arr,mid+1,high);
        // display(a3);
        // cout<<"Calling merge : "<<low<<" to "<<high<<endl;
        a1 = merge(a2,a3);
        // display(a1);
    }
    if(low==high)
    {
        a1.push_back(arr[low]);
        return a1;
    }
    return a1;
}


int main()
{
    vector<int> arr1 = {1, 2, 3, 5, 7, 8, 9, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 22, 23, 24, 25, 26, 27, 28, 29, 31, 32, 33, 34, 35, 37, 39, 40, 41, 42, 43, 45, 46, 50, 51, 52, 54, 55, 57, 58, 59, 60};
    vector<int> arr3 = mergeSort(arr1,0,arr1.size()-1);
    display(arr3);

    return 0;
}
