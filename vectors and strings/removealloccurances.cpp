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

int main(){
    string d="abcdaabcbaabcbc";
    string part="abc";
    int size2=part.size();
    while(d.length()>0 && d.find(part)<d.length()){
        int k=d.find(part);
        d.erase(k,size2);
    }
    cout<<d;
    
}