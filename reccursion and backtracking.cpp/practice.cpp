#include<iostream>
#include<string>
using namespace std;
void sumof(int &sum,int i,int n){
    if(i==n) return ;
    i=i+1;
    sum=sum+i;
    sumof(sum,i,n);
}
int sumof2(int i,int n){
    if(i==n) return n;
    return i+sumof2(i+1,n);
}
void factof(int i,int f,int n){
    if(i==n+1){
        cout<<f;
        return ;
    } 
    factof(i+1,f*i,n);
}
int factof2(int n){
    if(n==0 || n==1) return 1;
    return n*factof2(n-1);
}
bool ispalindrome(string s,int i){
    if(i>=s.length()/2) return true;
    if(s[i]!=s[s.length()-i-1]) return false;
    if(ispalindrome(s,i+1)) return true;
    return false;
}
int main(){
    int sum=0;
    sumof(sum,0,100);
    cout<<sum<<endl;
    cout<<sumof2(1,100)<<endl;
    cout<<factof2(5)<<endl;
    factof(1,1,5);
    cout<<endl<<ispalindrome("madam",0)<<endl;
}

