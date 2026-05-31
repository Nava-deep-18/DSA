#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <utility>
#include <stack>
#include <cstring>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cctype> //for isalnum,tolower functions

using namespace std;

int main(){
      string name=" man, a plan, a canal: Panama";
//       for(int i=0;i<name.size();i++){
//             if(name[i]<65 || name[i]>122 ||(name[i]>90 && name[i]<97)){
//                   name.erase(i,1);
//                   i--;
//             }
//       }
//       for (int i = 0; i < name.size(); i++) {
//         if (name[i] >= 'A' && name[i] <= 'Z') {  
//             name[i] = name[i] + 32;  
//         }
//     }
//     string name2=name;
//     for(int i=name.size()-1,j=0;i>0;i--,j++){
//            name2[j]=name[i];
//     }
//     if(name==name2){
//         cout<<"true";
//     }
//     else{
//       cout<<"false";
//     }
       
      int st=0,end=name.size()-1;
      while(st<=end){
            if(!isalnum(name[st])){
               st++;
               continue;
            }
            if(!isalnum(name[end])){
               end--;
               continue;
            }
            if(tolower(name[st])!=tolower(name[end])){
                  cout<<"false";
                  return 0;
            }
            st++;
            end--;
      }
      cout<<"true"<<endl;
}