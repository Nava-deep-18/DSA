#include<iostream>
#include<vector>
using namespace std;
class DisjointSet{
    public:
    vector<int>par,rank,size;
    DisjointSet(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    int findUpar(int node){
        if(node==par[node]){
            return node;
        }
        return par[node]=findUpar(par[node]);
    }
    void UnionByRank(int u,int v){
        int ulp_u=findUpar(u);
        int ulp_v=findUpar(v);
        if (ulp_u == ulp_v) return;
        if(rank[ulp_u]<rank[ulp_v]){
            par[ulp_u]=ulp_v;
        }
        else if(rank[ulp_u]>rank[ulp_v]){
            par[ulp_v]=ulp_u;
        }
        else{
            par[ulp_v]=ulp_u;
            rank[ulp_u]++;
        }
    }
    void UnionBySize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
int main(){
    DisjointSet ds(7);
    ds.UnionByRank(1, 2);
    ds.UnionByRank(2, 3);
    ds.UnionByRank(4, 5);
    ds.UnionByRank(6, 7);
    ds.UnionByRank(5, 6);
    if (ds.findUpar(3) == ds.findUpar(7)) {
        cout << "Same\n";
    }
    else {
        cout << "Not Same\n";
    }
    ds.UnionByRank(3, 7);
    if (ds.findUpar(3) == ds.findUpar(7)) {
        cout << "Same\n";
    }
    else {
        cout << "Not Same\n";
    }
    return 0;
}