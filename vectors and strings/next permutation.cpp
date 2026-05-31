#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
    int n=6;
    vector<int> a={1,2,3,6,5,4};
    int pivot=-1;
    for(int i=n-2;i>=0;i--){
         if(a[i]<a[i+1]){
            pivot=i;
            break;
         }
    }
    for(int i=n-1;i>pivot;i--){
        if(a[i]>a[pivot]){
            swap(a[i],a[pivot]);
            break;
        }
    }
    if(pivot==-1){
        reverse(a.begin(),a.end());
    }
    int i=pivot+1,j=n-1;
    while(i<=j){
        swap(a[i],a[j]);
        i++;
        j--;
    }
    for(int i=0;i<n;i++){
        cout<<a[i];
    }
}