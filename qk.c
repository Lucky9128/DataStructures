#include<stdio.h>


void display(int *arr, int k)
{
    for(int i=0;i<k;i++)
        printf("%d\t",arr[i]);
    printf("\n");
}

void swap(int *a1,int *a2)
{
    int temp = *a1;
    *a1 = *a2;
    *a2 = temp;
}

int part(int *A, int low, int high)
{
    int pvt = A[high];
    int i=low-1,j=high;

    for(int j=low;j<high;j++)
    {
        if(A[j]<pvt)
        {
            i++;
            swap(&A[i],&A[j]);
        }
    }
    swap(&A[i+1],&A[high]);
    return i+1;
}


void quick(int *arr, int low, int high)
{
    if(low<high)
    {
        int pivot = part(arr,low,high);
        // printf("pivot->%d\n",pivot);
        // display(arr,10);
        int i;
        // scanf("%d",&i);
        quick(arr,low,pivot-1);
        quick(arr,pivot+1,high);
    }
}

int IndexOf(int *arr,int low,int high,int val)
{
    while(low<=high)
    {
        int mid  = (low+high)/2;
        // printf(".");def 
        if(arr[mid]==val)
            return mid;

        if(arr[mid]<val)
            low = mid+1;
        else
            high=mid-1;
    }
    // printf("\n");
    return -1;
}
void main()
{
    int arr1[]={10,9,8,7,6,5,4,3,2,1,15,11,13,11,15,13};
    int arr2[]={1,2,3,4,5,6,7,8,9,22,21,21,22,23,10,23};
    quick(arr2,0,len-1);
    display(arr2,len);
}


