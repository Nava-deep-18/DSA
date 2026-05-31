#include <iostream>
#include <vector>
#include<algorithm> 
using namespace std;
// leetcode 33

int main()
{
    int n=8;
    int array[n]={3,4,5,6,7,0,1,2};
    int st=0;
    int end=n-1;
    int target=0;
    while(st<=end)
    {
      int mid=st+(end-st)/2;
      if (array[mid]==target)
      {
        cout<<mid;
        return 0;
      }
      else if(array[st]<=array[mid])
      {
        if(array[st]<=target && target<=array[mid])
        {
            end=mid-1;
        }
        else
        st=mid+1;
      }
      else
      {
        if(array[mid]<=target && target<=array[end])
        {
            st=mid+1;
        }
        else
        end=mid-1;
      }
    }
}