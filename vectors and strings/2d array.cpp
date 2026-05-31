#include <iostream>
#include <vector>
#include <algorithm> // for sorting
#include <list>
#include <deque>
#include <utility>
#include <stack>
using namespace std;

int main(){
   int matrix[3][3]={{1,2,3},{4,5,6},{7,8,9}};
// //search

//    int target;
//    cout<<"enter target:";
//    cin>>target;
//    pair<int,int>p={-1,-1};
//    for(int i=0;i<3;i++){
//     for(int j=0;j<3;j++){
//         if(matrix[i][j]==target){
//             p={i+1,j+1};
//         }
//       }
//    }
//    cout<<p.first<<" "<<p.second<<endl;

// // maxrowsum

// int msum=0;
// for(int i=0;i<3;i++){
//     int csum=0;
//     for(int j=0;j<3;j++){
//         csum=csum+matrix[i][j];
//      }
//     if(csum>msum){
//         msum=csum;
//    }   
//  }
//    cout<<msum;

// //diagonal sum

// //tc=n*n
// int n=3;
// int pdsum=0;
// int sdsum=0;
// for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//         if(i==j){
//             pdsum=pdsum+matrix[i][j];
//         }
//         else if(i+j==n-1){
//             sdsum=sdsum+matrix[i][j];
//         }
//      }
//    } 
// cout<<pdsum+sdsum;

// //tc=n
// int n=3;
// int sum=0;
// for(int i=0;i<n;i++){
//     sum=sum+matrix[i][i];
//     if(i!=n-i-1){
//         sum=sum+matrix[i][n-i-1];
//     }
// }
// cout<<sum;
}