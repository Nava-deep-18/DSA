#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <utility>
#include <stack>
#include <cstring>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
                         //STL
                         //vectors
    /*
    //uses dynamic allocation of memory
    //vector is a data structure like array but its size is not fixed
    vector<int>name;//size=0
    vector<int>name2={1,2,3};//vector size is 3
    cout<<name2[1];//output=2
    vector<int>name3(5,3);//5=sizeofvector,3=value at every box
    cout<<endl;
    for(int i:name3)
    {
        cout<<i;//for loop used only for vectors,here i is value at box output=33333
    }
    //functions used in vectors
    cout<<endl<<name3.size()<<endl; //prints size of vector
    name.push_back(25);//pushes 25 into the empty vector
    cout<<name[0]<<endl;//using push_back we can add elements in vector
    //similarly pop_back is used to delete only last element so no need to write any number in bracket
    cout<<name2.front()<<endl;//displays first element;
    //name2[2]=name2.at(2)//use of at function
    //there are two types of data static and dynamic 
    //static data is alloted during compile time and stak memory is used example is array
    //dynamic data is alloted during run time and heap memory is used eg is vector
    //when a element is pushed back into a vector without any space than the capacity of 
    //the vector us doubled 
    name2.push_back(25);
    cout<<name2.capacity()<<endl;
    cout<<name2.size()<<endl;
    //here the size is 4 but capcacity is 6
    
    */
//    list<int>name={4,5,6,7};
//    name.push_back(4);
//    name.pop_back();
//    auto it=name.begin();
//    advance(it,1);
//    name.insert(it,67);
//    for(auto it=name.begin();it!=name.end();it++){
//     cout<<*(it);
//    }
// deque<int>name={1,3,5,4};
//    name.insert(name.begin()+2,67);
//    for(int val:name){
//     cout<<val;
//    }
// vector<pair<int,int>>name={{1,2},{3,4},{5,6}};
//    name.emplace_back(7,8);
//    for(auto val:name){
//         cout<<val.first<<" "<<val.second<<endl;
//    }
// stack<int>s;
//    s.push(4);
//    s.push(5);
//    s.push(7);
//    s.push(49);
//    while(!s.empty()){
//     cout<<s.top();
//     s.pop();
//    }
    //  char name[10];
    //  cout<<"enter the name"<<endl;
    //  cin.getline(name,10,'.');
    //  cout<<name;
    //  cout<<strlen(name);
    // string name;
    // cout<<"enter name:"<<endl;
    // //cin>>name;
    // getline(cin,name);
    // string name2;
    // cout<<"enter name:"<<endl;
    // //cin>>name2;
    // getline(cin,name2);
    // string name3=name+name2;
    // reverse(name3.begin(),name3.end());
    // cout<<name3;
    
}    