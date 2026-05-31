#include <iostream>
#include <vector>
#include<algorithm> 
using namespace std;
//leetcode 540

int main()
{
   int n=7;
   int array[n]={1,1,2,2,3,4,4};

   //bruteforcemethod tc=n
//    for(int i=0;i<n;i++)
//    {
//     if(array[i]!=array[i-1] && array[i]!=array[i+1])
//     {
//         cout<<i<<endl;
//         return 0;
//     }
//    }

  //optimised tc=logn and sc=1
         int st=0,end=n-1;
         while(st<=end)
        {
            int mid=st+(end-st)/2;
            if(n==1)
            {
                cout<<array[0];
                return 0;
            }
            if(mid==0 && array[0]!=array[1])
            {
                cout<<array[mid];
                return 0;
            }
            if(mid==n-1 && array[n-1]!=array[n-2])
            {
               cout<<array[mid];
               return 0;
            }
            if(array[mid]!=array[mid-1] && array[mid]!=array[mid+1])
            {
                cout<<array[mid]<<endl;
                return 0;
            }
            if(mid%2==0)
            {

                if(array[mid]==array[mid-1])
                {
                   end=mid-1;
                }
                else
                    st=mid+1;
            }
            else
            {
                if(array[mid]==array[mid-1])
                {
                   st=mid+1;
                }
                else
                   end=mid-1;
            }
        }     


}

