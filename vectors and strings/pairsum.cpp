#include <iostream>
#include <vector>
#include<algorithm> //for sorting
using namespace std;
//leet code q1
//using two pointer approach

vector<int> findpairsum(vector<int> num,int target)
{
    vector<int>ans;
    int n=num.size();
    int i=0,j=n-1;
    sort(num.begin(),num.end());
    while(i<j)
    {
        int pairsum=num[i]+num[j];
        if(pairsum>target)
        j--;
        else if(pairsum<target)
        i++;
        else
        {
        ans.push_back(i);
        ans.push_back(j);
        return ans;
        }
    }
    return ans;
}
int main()
{
   vector<int>given={15,11,7,2};
   int target;
   cout<<"enter the target"<<endl;
   cin>>target;
   vector<int>final=findpairsum(given,target);
   cout<<final[0]<<","<<final[1]<<endl;
}
