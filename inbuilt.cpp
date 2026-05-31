#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstdio>
#include<cstring>
#include<cctype>
#include<unordered_set>
using namespace std;
int main(){

    //vectors

// vector<int>vec={1,2,3,5,6,3};//vector
// vec.insert(vec.begin()+1,9);//vector
// for(int val:vec){
//     cout<<val<<" ";
//  }
// cout<<endl<<*(max_element(vec.begin(),vec.begin()+3));//algorithm
// vec.erase(remove(vec.begin(),vec.end(),3),vec.end());//algorithm //vec.remove() returns an iterator
// //vec.erase() can also be used by passing only single iterator which removes single element
// cout<<endl;
// for(int val:vec){
//     cout<<val<<" ";
// }
// cout<<endl;

    //strings

string name="NAVADEEP";//string
cout<<name;
cout<<endl<<name.length();//string
name.insert(0,"k");//string
name.erase(0,1);//string
cout<<endl<<name<<endl;
cout<<"    "<<name.substr(0,2)<<endl;//string
cout<<strlen(name.c_str())<<endl;//cstring
cout<<name.append(" nindra")<<endl;//string
cout<<name.replace(8,6,"sety")<<endl;// replaces 6 length after 8th position //string
//push_back and pop_back are also functions in string headerfile
for(char &ch:name){
    ch=tolower(ch);//cctype
}
cout<<name<<endl;
cout<<isalnum('&')<<endl;//cctype
cout<<name.find("setya");//string

string str = "12345";
int num =stoi(str); //string
cout<<endl<<num;

string name2="pusha";
name2.append(5,'c');
cout<<endl<<name2;

    //unordered set
    
// unordered_set<int>given;//unordered_set
// given.insert(3);//unordered_set
// given.insert(2);
// given.insert(5);
// given.erase(5);//unordered_set 
// cout<<given.count(5)<<endl;//returns 1 if element is present else 0//unordered_set
// cout<<*(given.find(3))<<endl;//unordered_set//returns the iterator present at the number inside the find if it is present else it returns end() iterator
// for(int val:given){
//     if(given.find(val)!=given.end()){
//         cout<<val<<" is present"<<endl;
//     }
//   }


}