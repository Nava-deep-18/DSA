#include<iostream>
#include<vector>
using namespace std;
class FT{
    vector<int>fen;
    public:
    FT(int n){
        fen.resize(n+1,0);
    }
    void upadte(int i,int add){
        while(i<fen.size()){
            fen[i]+=add;
            i+=(i&(-i));
        }
    }
    int sum(int i){
        int s=0;
        while(i>0){
            s+=fen[i];
            i=i&(i-1);
        }
        return s;
    }
    int rangesum(int l,int r){
        return sum(r)-sum(l-1);
    }
};
/*
Question:

You are given an array of N integers.

Process Q queries of the following types:

Type 1:
1 l r

Print the sum of elements in the range [l, r].

Type 2:
2 i val

Add val to the element at index i.

Use a Fenwick Tree (Binary Indexed Tree) to efficiently support
both operations.

Example:

Array: [1, 2, 3, 4, 5]

1 2 4
Output: 9

2 3 10

Array becomes:
[1, 2, 13, 4, 5]

1 2 4
Output: 19
*/

void solve(){
    int n;
    cout<<"enter size of array : ";
    cin>>n;
    vector<int>vec(n+1);
    FT ft(n);
    for(int i=1;i<=n;i++){
        cin>>vec[i];
        ft.upadte(i,vec[i]);
    }
    int q;
    cout<<"enter number of queries : ";
    cin>>q;
    while(q--){
        int type;
        cout<<"enter type of query : ";
        cin>>type;
        if(type==1){
            int l,r;
            cin>>l>>r;
            cout<<ft.rangesum(l,r)<<endl;
        }
        else if(type==2){
            int i,val;
            cin>>i>>val;
            vec[i]+=val;
            ft.upadte(i,val);
        }
    }
}
int main(){
    solve();
    return 0;
}