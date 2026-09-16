class Solution {
public:
int time=0;
vector<int>dt,low;

void dfs(int u,int parU,vector<bool>&vis,vector<vector<int>>&bridges,vector<vector<int>>&G){
    vis[u]=true;
    dt[u]=low[u]=++time;
    for(int v:G[u]){//for each neighbour
    //case 1: not visited
    if(!vis[v]){
        dfs(v,u,vis,bridges,G) ;
        low[u]=min(low[u],low[v]);
        if(low[v]>dt[u]) bridges.push_back({u,v});

    }
    //case 2 parent and visted = ignore 

    //case 3 not parent and visted
    else if(v!=parU){
        low[u]=min(low[u],dt[v]);

    }

    }
}
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //construct the undirected graph;
        vector<vector<int>>G(n);
        
        
        for(auto c: connections){
           G[c[1]].push_back(c[0]);
           G[c[0]].push_back(c[1]);
        }
        // vector<vector<int>> adj;
//    for(int i=0; i<connections.size(); i++) {
//         int u = connections[i][0];
//         int v = connections[i][1];
//        adj[u].push_back(v);
//        adj[v].push_back(u);
//       }
       vector<bool>vis(n,false);
       dt.resize(n); //dt of length n as it was declared golbals o we resized it here
       low.resize(n);
       time=0;
       
  vector<vector<int>>bridges;
  for(int i=0;i<n;i++){
    if(!vis[i]) dfs(i,-1,vis,bridges,G) ;  // to make sure we cover disconnected components also suppose they provide more tahn one graph  // intial parent will be -1;
  }
       
       return bridges;
        
    }
};