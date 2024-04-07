struct DSU {
public: 
  vector<int> parent,size;
  int n;

  DSU(int _n)
  {
    n=_n;
    parent.resize(n+1);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++) parent[i]=i;
  }
  
  int findUlPar(int u)
  {
    if(parent[u]==u) return u;
    return parent[u] = findUlPar(parent[u]);
  }

  void merge(int u,int v)
  {
    int ulp_u = findUlPar(u);
    int ulp_v = findUlPar(v);

    if(ulp_u == ulp_v)  return;

    if(size[ulp_u]<size[ulp_v]){
      swap(ulp_u,ulp_v);
      swap(u,v);
    }

    size[ulp_u]+=size[ulp_v];
    parent[ulp_v]=ulp_u;
  }

  
};