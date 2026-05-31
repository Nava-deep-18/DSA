#include <iostream>
#include <vector>
using namespace std;
//leet code q169
// by moores voting algorithm
// a element is majority element if it is present more than n by 2 times in the vector
//since the ans to be found should have frequency greater than size/2 its frequency will 
//never equal to zero in this loop
int main()
{
   int freq=0,ans=0;
   vector<int>given={1,2,3,4,2,2,2};
   int n=given.size();
   for(int i=0;i<n;i++)
   {
    if(freq==0)
    {
        ans=given[i];
    }
    if(ans==given[i])
    {
        freq++;
    }
    else
    freq--;
   }
   int count=0;
   for(int val:given)
   {
    if(val==ans)
    count++;
   }
   if(count<=n/2)
   {
      ans=-1;//there is no majority element
   }
   cout<<ans;
}