#include<iostream>
#include<vector>
using namespace std;
class SGT{
public:
    vector<int>seg;
    vector<int>lazy;
    SGT(int n){
        seg.resize(4*n);
        lazy.resize(4*n,0);
    }
    void build(int idx,int low,int high,vector<int>& vec){
        if(low==high){
            seg[idx]=vec[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(2*idx+1,low,mid,vec);
        build(2*idx+2,mid+1,high,vec);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }

    int queries(int idx,int low,int high,int l,int r){
        //update prev remaining updates and propagate downwards
        if(lazy[idx]!=0){
            seg[idx]+=(high-low+1)*lazy[idx];
            // propagate the lazy update downwards for remaining nodes to get updated
            if(low!=high){
                lazy[2*idx+1]+=lazy[idx];
                lazy[2*idx+2]+=lazy[idx];
            }
            lazy[idx]=0;
        }

        //complete overloap
        //l low high r
        if(l<=low && high<=r) return seg[idx];

        //no overloap
        // l r low high    or    low high l r
        if(r<low || high<l) return 0;

        //else is partial overloap
        int mid=low+(high-low)/2;
        int left=queries(2*idx+1,low,mid,l,r);
        int right=queries(2*idx+2,mid+1,high,l,r);
        return left+right;
    }

    void update(int idx,int low,int high,int l,int r,int val){
        //update prev remaining updates and propagate downwards
        if(lazy[idx]!=0){
            seg[idx]+=(high-low+1)*lazy[idx];
            // propagate the lazy update downwards for remaining nodes to get updated
            if(low!=high){
                lazy[2*idx+1]+=lazy[idx];
                lazy[2*idx+2]+=lazy[idx];
            }
            lazy[idx]=0;
        }

        //no overloap we dont do anythign
        // l r low high    or    low high l r
        if(r<low || high<l) return;

        //complete overloap
        //l low high r
        if(l<=low && high<=r){
            seg[idx]+=(high-low+1)*val;
            // propagate the lazy update downwards for remaining nodes to get updated
            if(low!=high){
                lazy[2*idx+1]+=val;
                lazy[2*idx+2]+=val;
            }
            return;
        }

        int mid=low+(high-low)/2;
        update(2*idx+1,low,mid,l,r,val);
        update(2*idx+2,mid+1,high,l,r,val);
        seg[idx]=seg[2*idx+1]+seg[2*idx+2];
    }
};

/*
Question:
Given an array of N integers.

Type 1 l r
Find the sum of elements in the range [l,r].

Type 2 l r val
Add val to every element in the range [l,r].

Use Segment Tree with Lazy Propagation.
*/

void solve(){
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
            int l,r,val;
            cin>>l>>r>>val;
            sgt.update(0,0,n-1,l,r,val);
        }
    }
}

int main(){
    solve();
    return 0;
}