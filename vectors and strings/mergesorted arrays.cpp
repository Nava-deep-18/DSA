#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){
    int m=3,n=3;
    int a[6]={1,2,3,0,0,0};
    int b[3]={2,5,6};
    int index=m+n-1;
    int i=m-1,j=n-1;
    while(i>=0 && j>=0){
        if(a[i]<=b[j]){
            a[index]=b[j];
            j--;
            index--;
        }
        else{
            a[index]=a[i];
            i--;
            index--;
        }
    }
    while(j>=0){
        a[index]=b[j];
        index--;
        j--;
    }
    for(int i=0;i<m+n;i++){
        cout<<a[i];
    }

    // if you want to store it in new array
    
    // int m=3,n=3;
    // int a[6]={1,2,3};
    // int b[3]={2,5,6};
    // int index=m+n-1;
    // int array[m+n]={0};
    // int i=n-1,j=n-1;
    // while(i>=0 && j>=0){
    //     if(a[i]<=b[j]){
    //         array[index]=b[j];
    //         j--;
    //         index--;
    //     }
    //     else{
    //         array[index]=a[i];
    //         i--;
    //         index--;
    //     }
    // }
    // while(i>=0){
    //     array[index]=a[i];
    //     index--;
    //     i--;
    // }
    // while (j >= 0) {
    //     array[index] = b[j];
    //     index--;
    //     j--;
    // }
    // for(int i=0;i<m+n;i++){
    //     cout<<array[i];
    // }
}
