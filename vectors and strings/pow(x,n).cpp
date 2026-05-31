#include<iostream>
#include<vector>
using namespace std;
//leet code q50
int main()
{
    int n;
    double x;
    cout<<"enter base and power"<<endl;
    cin>>x>>n;
    long binForm=n;
     double ans=1;
    if(n<0)
    {
        binForm=-binForm;
        x=1/x;
    }
    while(binForm>0)
    {
        if(binForm%2==1)
        {
            ans=ans*x;
            x=x*x;
        }
        else
        x=x*x;
        binForm=binForm/2;
    }
    cout<<"the power of number is "<<ans<<endl;
}
