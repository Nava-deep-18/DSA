#include <iostream>
#include <vector>
using namespace std;
//space complexity 1
int main(){
vector<int>nums={1,3,4,2,2};
int slow=nums[0];
int fast=nums[0];
do{
    slow=nums[slow];
    fast=nums[nums[fast]];
}
while(slow!=fast);

while(slow!=fast){
  slow=nums[slow];
  fast=nums[fast];
}
cout<<slow;
}