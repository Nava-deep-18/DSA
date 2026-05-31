#include<iostream>
#include<vector>
using namespace std;

int main()
{
    //brute force method  tc=n*n

    // int nums[4]={1,2,3,4};
    // int ans[4];
    // for(int i=0;i<4;i++)
    // {
    //     int a=1;
    //     for(int j=0;j<4;j++)
    //     {
    //         if(i==j)
    //         {
    //             continue;
    //         }
    //         a=a*nums[j];
    //     }
    //     ans[i]=a;
    // }
    // // for(int i=0;i<4;i++)
    // // {
    // //     cout<<ans[i]<<" ";
    // // }

//optimised method tc=n

int n=4;
int num[n]={1,2,3,4};
int prefix[n],suffix[n],ans[n];
prefix[0]=1;suffix[n-1]=1;
for(int i=1;i<n;i++)
{
    prefix[i]=prefix[i-1]*num[i-1];
}
for(int i=n-2;i>=0;i--)
{
    suffix[i]=suffix[i+1]*num[i+1];
}
for(int i=0;i<n;i++)
{
    ans[i]=prefix[i]*suffix[i];
}
for(int val:ans){
    cout<<val;
}
// for(int i=0;i<4;i++)
// {
//         cout<<ans[i]<<" ";
// }
//tc=n+n+n=3n=n
}