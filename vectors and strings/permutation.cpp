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
#include <cctype>

using namespace std;

bool isfreqsame(int freq[],int windowfreq[]){
    for(int i=0;i<26;i++){
        if(freq[i]!=windowfreq[i]){
            return false;
        }
    }
    return true;
}
int main(){
    string s1="abc";
    string s2="kklsdfcabdkwf";
    int freq[26]={0};
    for(int i=0;i<s1.length();i++){
        freq[s1[i]-'a']++;
    }
    int windsize=s1.length();
    for(int i=0;i<s2.length();i++){
         int windidx=0;
         int idx=i;

         int windfreq[26]={0};
         while(idx<s2.length() && windidx<windsize){
            windfreq[s2[idx]-'a']++;
            windidx++;
            idx++;
        }
        if(isfreqsame(freq,windfreq)){
            cout<<"true";
            return 0;
        }
    }
    cout<<"false";
    
}