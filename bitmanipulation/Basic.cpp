#include<iostream>
using namespace std;

//13 in binary is 1101

//swap

// int main(){
//     int a=5;
//     int b=6;
//     a=a^b;
//     b=a^b;
//     a=a^b;
//     cout<<"a="<<a<<" , b="<<b<<endl;
// }

//checking ith bit set or not

// int main(){
//     int n=13;
//     int i;
//     cout<<"enter the positional value of bit:";
//     cin>>i;

//     //method 1 (using left shift)
//     //taking 1 to the bit to be checked by leftshift operator and using & operator with n

//     // if((n&(1<<i))!=0){
//     //     cout<<"the bit is set"<<endl;
//     // }
//     // else{ 
//     //     cout<<"the bit is not set"<<endl;
//     // }
    
//     //method 2(using right shift)
//     //taking the bit to be checked to right most by right shift operator and usind & operator with 1
    
//     // if(((n>>i)&1)!=0){
//     //     cout<<"the bit is set"<<endl;
//     // }
//     // else{
//     //     cout<<"the bit is not set"<<endl;
//     // }
// }

//set the ith bit

// int main(){
//     int n=13;
//     int i;
//     cout<<"enter the value of i:";
//     cin>>i;
//     //to set
//     n=(n|(1<<i));
//     //to check setting of bit done or not
//     cout<<((n&(1<<i))?1:0);
// }

//clear the ith bit

// int main(){
//     int n=13;
//     int i;
//     cout<<"enter the value of i:";
//     cin>>i;
//     //to clear
//     n=(n&(~(1<<i)));
//     //to check clearing of bit done or not
//     cout<<((n&(1<<i))?1:0);
// }

//toggle the ith bit

// int main(){
//     int n=13;
//     int i;
//     cout<<"enter the value of i:";
//     cin>>i;
//     //to toggle
//     n=(n^(1<<i));
//     //to check toggling of bit done or not
//     cout<<((n&(1<<i))?1:0);
// }

//change the last set bit to zero

// int main(){
//     int n=14;
//     //now consider binary representaion of 32 i.e.100000
//     //now consider binary of 31 i.e 011111
//     //take 13=1101 12=1100
//     //take 14=1110 13=1101
//     //n-1 will be obtained by making last set bet to zero and next bits after the last set bit to 1
//     n=n&(n-1);
//     cout<<n;
// }

//check if number is power of 2

// int main(){
//     // if it is power of 2 it always contian only 1 set bit
//     // n&(n-1) = 0 always
//     int n;
//     cout<<"enter the value of n:";
//     cin>>n;
//     if((n&(n-1))==0){
//         cout<<"the number is power of 2"<<endl;
//     }
//     else{
//         cout<<"the number is not power of 2"<<endl;
//     }
// }

//countng number of set bit

// int main(){
//   int n=31;
//   int count=0;
//   //method 1
//   while(n!=0){
//     count=count+(n&1); //because odd number will have last bit 1 so n&1 will be 1 if n is odd
//     n=n>>1; //bitwise operators are slightly faster then division
//   }
//   cout<<count<<endl;

//   //method 2 //tc=O(number of bits) better form many problems
//   while(n!=0){
//     n=n&(n-1);
//     count++;
//   }
//   cout<<count<<endl;
// }




