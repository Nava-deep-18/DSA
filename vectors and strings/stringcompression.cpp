#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<char> chars={'a','a','b','b','a','a','c','c','c'};
    int n=chars.size();
    int index=0;
    for(int i=0;i<n;1){
        char pc=chars[i];
        int count=0;
        while(i<n && chars[i]==pc){
             count++,i++;
        }
        if(count==1){
            chars[index++]=pc;
        }
        else{
            chars[index++]=pc;
            string str=to_string(count);
            for(char digits:str){
                chars[index++]=digits;
            }
        }
    }
    chars.resize(index);
    for(int i=0;i<chars.size();i++){
        cout<<chars[i];
    }
    cout<<endl<<index;
}
