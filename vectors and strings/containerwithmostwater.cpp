#include<iostream>
#include<vector>
using namespace std;
//leet code q11
int main()
{
    //Brute force method tc=n*n

    // int maxwater=0;
    // int heights[9]={1,8,6,2,5,4,8,3,7};
    // for(int i=0;i<8;i++)//8=n-1
    // {
    //     for(int j=i+1;j<9;j++)//9=n
    //     {
    //       int area=(j-i)*min(heights[i],heights[j]);
    //       maxwater=max(maxwater,area);
    //     }
    // }
    // cout<<maxwater;
    
    //optimise method tc=n

    int ans=0;
    int heights[9]={1,8,6,2,5,4,8,3,7};
    int lp=0,rp=8;
    while(lp<rp)
    {
        int curwt=(rp-lp)*min(heights[lp],heights[rp]);
        ans=max(ans,curwt);
        if(heights[lp]<heights[rp]){
            lp++;
        }
        else{
            rp--;
        }
    }
    cout<<ans<<endl;

    //generally two pointer approach reduces the time complexity from (n square) to n
}