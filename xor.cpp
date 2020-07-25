#include<iostream>
#include<vector>
#define debug 0


using namespace std;

void display(vector<int> arr)
{
    for(int i=0;i<arr.size();i++)
        cout<<arr[i]<<"\t";
    cout<<endl;
}

/* int main()
{
    vector<int> arr = {1,3,4,8};
    int k=2;
    // cin>>N>>k;
    long temp = k*(k+1)/2;
    int sum =temp;
    vector<int> stack(k+1);
    fill(stack.begin(),stack.end(),0);
    vector<int> fla = {2, 2, 1, 1, 2, 2, 2, 1, 2, 2, 2, 1, 1, 2, 2, 1, 1, 1, 2, 1, 2, 1, 1, 2, 2, 1, 1, 1, 1, 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 1, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 2, 1, 1, 1, 2, 1, 2, 1, 1, 1, 1, 2, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2};
    int strt=0,end=0;
    int max=-1;
    // sum-=fla[strt];
    for(int i=0;i<fla.size();i++)
    {
        if(debug)
        cout<<i<<"->"<<fla[i]<<endl;
        
        if(stack[fla[i]]==0)
        {
            sum-=fla[i];
            if(debug)
            cout<<"first occurence of "<<fla[i]<<" -> "<<sum<<endl;
        }
        stack[fla[i]]++;
        if(sum == 0)
        {
            if(debug)
            cout<<"Sum become 0 at "<<fla[i]<<" -> "<<sum<<endl;
            int temp2 = i-strt;
            if(debug)
            cout<<"new len "<<temp<<" pre max  "<<max<<endl;
            if(max<temp2)
            {
                cout<<"Max updated from "<<max<<" to "<<temp2<<endl;
                max=temp2;
            }
            while(sum==0)
            {
                stack[fla[strt]]--;
                if(debug)
                    cout<<"stack "<<stack[fla[strt]];
                if(stack[fla[strt]]==0)
                {
                    sum+=fla[strt];
                if(debug)
                    cout<<" inc sum "<<sum;
                }
                if(debug)
                    cout<<" dec "<<fla[strt];
                strt++;
                if(debug)
                    cout<<" -> "<<sum<<" strt ->"<<strt<<endl;
            }
            if(debug)
            cout<<"New strt "<<strt<<" -> "<<sum<<endl;
        }
        end++;
    }
    int temp2 = end-strt;
    if(temp2>max)
        max=temp2;
    cout<<"Max->"<<max<<endl;
    return 0;
}*/

int main()
{
    vector<int> arr ={1,2,3,4,5};
    vector<int> arr2 = {7,8,9};

    arr.insert(arr.begin()+2,arr2.begin(),arr2.end());
    display(arr);
    display(arr2);

    return 0;
}
