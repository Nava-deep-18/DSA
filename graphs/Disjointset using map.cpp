#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
class DisjointSet {
    unordered_map<long long, long long> parent;
    unordered_map<long long, int> size;
public:
    long long findUPar(long long node) {
        if (parent.find(node) == parent.end()) {
            parent[node] = node;
            size[node] = 1;
            return node;
        }
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(long long u, long long v) {
        long long ulp_u = findUPar(u);
        long long ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};