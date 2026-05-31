#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(){

    int n=9;
    int array[n]={1,1,2,2,1,0,0,2,0};
//     //1st approach
//     int count0s=0,count1s=0,count2s=0;
//     for(int i=0;i<n;i++){
//         if(array[i]==0){
//             count0s++;
//         }
//         else if(array[i]==1){
//             count1s++;
//         }
//         else{
//             count2s++;
//         }
//     }
//     int initial=0;
//     for(int i=0;i<count0s;i++){
//         array[initial]=0;
//         initial++;
//     }
//     for(int i=0;i<count1s;i++){
//         array[initial]=1;
//         initial++;
//     }
//     for(int i=0;i<count2s;i++){
//         array[initial]=2;
//         initial++;
//     }
    // Dutch national flag algorithm
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(array[mid]==0){
            swap(array[low],array[mid]);
            mid++;
            low++;
        }
        else if(array[mid]==1){
            mid++;
        }
        else{
            swap(array[high],array[mid]);
            high--;
        }
    }
}