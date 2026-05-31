#include<iostream>
#include<vector>
using namespace std;
//leet code q121
int main()
{
    int price[6]={7,1,5,3,6,4};
    int maxprofit=0;
    int bestbuy=price[0];
    for(int i=1;i<6;i++)
    {
        if(price[i]>bestbuy)
        {
            maxprofit=max(maxprofit,price[i]-bestbuy);
        }

        bestbuy=min(bestbuy,price[i]);
    }
    cout<<maxprofit<<endl;
}