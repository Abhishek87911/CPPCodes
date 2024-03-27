class DSU {
    vector<int>  parent, size; 
    int mx=0;
    int noOfComponents;
public: 
    DSU(int n) {
        
        parent.resize(n+1);
        size.resize(n+1); 
        for(int i = 0;i<=n;i++) {
            parent[i] = i; 
            size[i] = 1; 
            noOfComponents=n;
        }
    }

    int findUPar(int node) {
        if(node == parent[node])
            return node; 
        return parent[node] = findUPar(parent[node]); 
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u); 
        int ulp_v = findUPar(v); 
        if(ulp_u == ulp_v) return; 
        if(size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v; 
            size[ulp_v] += size[ulp_u]; 
            mx=max(mx,size[ulp_v]);
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v]; 
            mx=max(mx,size[ulp_u]);
        }
        noOfComponents--;
    }
  int giveNoOfComponenets() {
    return noOfComponents;
  }

};