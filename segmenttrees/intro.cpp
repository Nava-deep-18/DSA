#include<iostream>
#include<climits>
#include<vector>
using namespace std;
class SGT{
public:
    vector<int>seg;
    SGT(int n){
        seg.resize(4*n);
    }
    void build(int idx,int low,int high,vector<int>& vec){
        if(low==high){
            seg[idx]=vec[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(2*idx+1,low,mid,vec);
        build(2*idx+2,mid+1,high,vec);
        seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
    }
    int queries(int idx,int low,int high,int l,int r){
        //complete overloap
        //l low high r
        if(l<=low && high<=r) return seg[idx];

        //no overloap
        // l r low high    or    low high l r
        if(r<low || high<l) return INT_MAX;

        //else is partial overloap
        int mid=low+(high-low)/2;
        int left=queries(2*idx+1,low,mid,l,r);
        int right=queries(2*idx+2,mid+1,high,l,r);
        return min(left,right);
    }
    void update(int idx,int low,int high,int i,int val){
        if(low==high){
            seg[idx]=val;
            return;
        }
        int mid=low+(high-low)/2;
        if(i<=mid) update(2*idx+1,low,mid,i,val);
        else update(2*idx+2,mid+1,high,i,val);
        seg[idx]=min(seg[2*idx+1],seg[2*idx+2]);
    }
};

/*
Question:

Given an array of N integers, process Q queries.

Query Type 1:
1 l r
Return the minimum element in the subarray from index l to r (inclusive).

Query Type 2:
2 i val
Update the element at index i to val.

Constraints are large, so implement the solution using a Segment Tree.

Example:

Array:
[5, 2, 8, 1, 7]

1 1 3
Output: 1

2 3 6
Array becomes:
[5, 2, 8, 6, 7]

1 1 3
Output: 2
*/

void solve1(){
    int n;
    cout<<"enter size of array : ";
    cin>>n;
    vector<int>vec(n);
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    SGT sgt(n);
    sgt.build(0,0,n-1,vec);
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
            cout<<sgt.queries(0,0,n-1,l,r)<<endl;
        }
        else if(type==2){
            int i,val;
            cin>>i>>val;
            vec[i]=val;
            sgt.update(0,0,n-1,i,val);
        }
    }
}

/*
Question:

You are given two arrays:

arr1 of size N1
arr2 of size N2

Process Q queries.

Query Type 1:
1 l1 r1 l2 r2

Find:
minimum element in arr1[l1...r1]
minimum element in arr2[l2...r2]

Output the smaller of these two minimum values.

Query Type 2:
2 vecNo idx val

If vecNo = 1:
    Update arr1[idx] = val

If vecNo = 2:
    Update arr2[idx] = val

Use Segment Trees to efficiently support range minimum queries
and point updates on both arrays.

Example:

arr1 = [5, 2, 8, 1]
arr2 = [7, 4, 9, 3]

1 0 2 1 3

min(arr1[0..2]) = 2
min(arr2[1..3]) = 3

Output:
2

2 2 3 0

arr2 becomes:
[7, 4, 9, 0]

1 0 2 1 3

min(arr1[0..2]) = 2
min(arr2[1..3]) = 0

Output:
0
*/

void solve2(){
    int n1;
    cout<<"enter size of array1 : ";
    cin>>n1;
    vector<int>vec1(n1);
    for(int i=0;i<n1;i++){
        cin>>vec1[i];
    }
    SGT sgt1(n1);
    sgt1.build(0,0,n1-1,vec1);
    int n2;
    cout<<"enter size of array2 : ";
    cin>>n2;
    vector<int>vec2(n2);
    for(int i=0;i<n2;i++){
        cin>>vec2[i];
    }
    SGT sgt2(n2);
    sgt2.build(0,0,n2-1,vec2);
    int q;
    cout<<"enter number of queries : ";
    cin>>q;
    while(q--){
        int type;
        cout<<"enter type of query : ";
        cin>>type;
        if(type==1){
            int l1,r1,l2,r2;
            cin>>l1>>r1>>l2>>r2;
            cout<<min(sgt1.queries(0,0,n1-1,l1,r1),sgt2.queries(0,0,n2-1,l2,r2))<<endl;
        }
        else if(type==2){
            int vecNo,i,val;
            cin>>vecNo>>i>>val;
            if(vecNo==1){
                vec1[i]=val;
                sgt1.update(0,0,n1-1,i,val);
            }
            else{
                vec2[i]=val;
                sgt2.update(0,0,n2-1,i,val);
            }
        }
    }
}
int main(){
    solve1();
    return 0;
}