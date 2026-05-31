#include <iostream>
#include <vector>
using namespace std;
int main()
{
//leet code q53
// maximum subarray sum

   // printing all possible subbarrays
    // int n=7;
    // int arr[7]={3,-4,5,4,-1,7,-8};
    // for(int st=0;st<n;st++)
    // {
    //     for(int end=st;end<n;end++) 
    //     {
    //         for(int i=st;i<=end;i++)
    //         {
    //              cout<<arr[i]<<" ";
    //         }  
    //         cout<<"    ";
    //     }
    //     cout<<endl;
    // }
    

    //Brute force method

    // int n=7;
    // int arr[7]={3,-4,5,4,-1,7,-8};
    // int maxsum=0;
    // for(int st=0;st<n;st++)
    // {  
    //     int csum=0;
    //     for(int end=st;end<n;end++)
    //     {
    //         csum+=arr[end];
    //         maxsum=max(csum,maxsum);
    //     }
    // }
    // cout<<"max sum is "<<maxsum<<endl;

   // using kadane's algorithm
   //value of current sum will never be negative for maximum subarray sum

    int n=7;
    int arr[7]={3,-4,5,4,-1,7,-8};
    int  maxsum=arr[0];
    int csum=0;
    for(int i=0;i<n;i++)
    {
        csum+=arr[i];
        maxsum=max(csum,maxsum);
        if(csum<0)
        {
            csum=0;
        }
        //return atlast becaue if all elements are negative atleast first element is 
        //to be considered
    }
    cout<<"max sum of the subarray is "<<maxsum<<endl;  
}
