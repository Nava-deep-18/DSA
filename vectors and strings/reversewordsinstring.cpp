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
  string name="a good     example";
  reverse(name.begin(),name.end());
  int size=name.length();
  string ans="";
  for(int i=0;i<size;i++){
    string word="";
    while(i<size && name[i]!=' '){
      word=word+name[i];
      i++;
    }
    if(word.length()>0){
    reverse(word.begin(),word.end());
    ans=ans+" "+word;
    }
  }
  cout<<ans.substr(1);
}