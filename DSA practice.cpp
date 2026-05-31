#include <iostream>
#include <vector>
#include <algorithm> // for sorting
#include <list>
#include <deque>
#include <utility>
#include <stack>
#include <unordered_set>
#include <string>
#include <map>
#include<unordered_map>
#include<cctype>
using namespace std;

// //happy number 

// class solution{
//    public:
//    void sumofdigits(int &n){
//       long long int sum=0;
//      while(n>0){
//       sum=sum+(n%10)*(n%10);
//       n=n/10;
//      }
//      n=sum;
//    }
//    bool ishappy(int n){
//    vector<int>seen;
//    while(n!=1){
//       sort(seen.begin(),seen.end());
//       if(binary_search(seen.begin(),seen.end(),n)){
//          return false;
//       }
//       seen.push_back(n);
//       sumofdigits(n);
//      }
//      return true;
//    }
// };

// int main(){
// int n;
// cout<<"enter the number:";
// cin>>n;
// solution a;
// cout<<a.ishappy(n);
// }

// int main(){
  // unordered_set<int>s;
  // s.insert(1);
  // s.insert(0);
  // s.insert(2);
  // vector<int>ans;
  // for(int val:s){
  //   ans.push_back(val);
  // }
  // cout<<ans[0]<<" "<<ans[1]<<ans[2]<<endl;
  // vector<int>nums={7,9,11,12,5};
  // int st=0;
  // int end=nums.size()-1;
  // int mini=INT8_MAX;
  // int idx=0;
  // while(st<=end){
  //   int mid=st+(end-st)/2;
  //   if(nums[mid]<mini){
  //     mini=nums[mid];
  //     idx=mid;
  //   }
  //   if(nums[mid]<=nums[end]){
  //     end=mid-1;
  //   }
  //   else{
  //     st=mid+1;
  //   }
  // }
  // cout<<idx;
  // string str1="navadeep";
  // cout<<str1.find_first_of("navae");
//}

// int main(){
//   std::map<int, std::string> mp = {{1, "one"}, {2, "two"}, {3, "three"}};

//   auto it = mp.find(2);  // Searching for key 2
//   if (it != mp.end()) {
//       std::cout << "Key found: " << (*it).first << ", Value: " << it->second << std::endl;
//   } else {
//       std::cout << "Key not found" << std::endl;
//   }

//   return 0;
// }

// int main() {
//   std::string str = "hello world";

//   // Trying to find a non-existent substring
//   int pos = str.find("xyz");

//   if (pos == std::string::npos) {
//       std::cout << "'xyz' not found!" << std::endl;
//   } else {
//       std::cout << "'xyz' found at index: " << pos << std::endl;
//   }

//   return 0;
// }  

// int main(){
//   string s="navadeep";
//   for(int i=0;i<s.size()-1;i++){
//     for(int j=i;j<s.size();j++){
//       cout<<s.substr(i,j-i+1)<<endl;
//     }
//   }
// }

int main(){
  int n=12;
  string res="";
  while(n!=0){
    if(n%2==0){
      res.push_back('0');
    }
    else res.push_back('1');
    n=n/2;
  }
  reverse(res.begin(),res.end());
  cout<<res;
}