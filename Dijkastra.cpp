void Dijkastra(int s,int n,vector<ll> &dist,vector<ll> &parent,vector<vector<pair<ll,ll>>> &adj){
  dist.assign(n,INF);
  parent.assign(n,-1);
  dist[s]=0;
  priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;
  q.push({0,s});
  while(!q.empty()){
    pair<ll,ll> curr = q.top();
    q.pop();
    int v = curr.second;
    ll d_v = curr.first;
    if(d_v!=dist[v]){
      continue;
    }

    for(auto edge: adj[v]){
      if(dist[v]+edge.second<dist[edge.first]){
        dist[edge.first] = dist[v]+edge.second;
        parent[edge.first] = v;
        q.push({dist[edge.first],edge.first});
      }
    }


  }

}