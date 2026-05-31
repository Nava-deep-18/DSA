#include <iostream>
#include <vector>
#include<algorithm> 
using namespace std;
// leetcode 852

int main()
{
   int n=6;
   int array[n]={0,3,8,9,5,2};

   //brute force //linearsearch method//tc=n
//    for(int i=1;i<n-1;i++)
//    {
//     if(array[i]>array[i-1] && array[i]>array[i+1])
//     {
//         cout<<i;
//     }
//    }

    //binarysearch method //tc=1
    int st=1,end=n-2;//when mid =0 or mid =n-1 the conditions are not correct
    while(st<=end)
    {
        int mid=st+(end-st)/2;
        if(array[mid]>array[mid-1] && array[mid]>array[mid+1])
        {
            cout<<mid;
            break;
        }
        else if(array[mid]<array[mid+1])
        {
            st=mid+1;
        }
        else
        {
            end=mid-1;
        }
    }  
}        