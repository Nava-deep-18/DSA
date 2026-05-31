#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;


void bubblesort(int array[],int n){
//in n-1 iterations adjacent elements are checked,compared and largest element is pushed by using swap function    
   for(int i=0;i<n-1;i++){
    bool isswap=false;
       for(int j=0;j<n-i-1;j++){
        if(array[j]>array[j+1]){
            swap(array[j],array[j+1]);
            isswap=true;
            }
         }
         if(!isswap){
            return;
        }    
    }
}
void selectionsort(int array[],int n){
   for(int i=0;i<n-1;i++){
    int SI=i;
    for(int j=i+1;j<n;j++){
       if(array[j]<array[SI]){
        SI=j;
       }
    }
    swap(array[i],array[SI]);
  }
}
void insertionsort(int array[],int n){
   for(int i=1;i<n;i++){
     int cur=array[i];
     int previous=i-1;
     while(previous>=0 && array[previous]>cur){
        array[previous+1]=array[previous];
        previous--;
     }
     array[previous+1]=cur;
   } 
}
void printarray(int array[],int n){
    for(int i=0;i<n;i++){
        cout<<array[i];
    }
}
int main(){
   int n=5;
   int array[5]={4,1,5,2,3};
    
   printarray(array,n);
}    