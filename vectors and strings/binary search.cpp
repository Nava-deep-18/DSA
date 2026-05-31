#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //linear search approach tc=n
    //binary search approac tc=logn,applicable only for sorted arrays

    int n=7;
    int num[n]={-1,0,3,4,5,9,12};
    int st=0,end=n-1;
    int target=0;
    int ans;
     while(st<=end)
     {
        int mid=(st+end)/2;
        if(target>num[mid])
        {
            st=mid+1;
        }
        else if(target<num[mid])
        {
            end=mid-1;
        }
        else
        {
            ans=mid;
            break; 
        }
     }  
     cout<<ans;
     //it also works for even

     //mid=st+(end-st)/2 should be used because if we do st+end for st and end
     //both equal to INT_MAX then overflow will take place

}