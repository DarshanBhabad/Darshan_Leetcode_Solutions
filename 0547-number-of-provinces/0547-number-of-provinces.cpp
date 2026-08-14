class Solution {
public:
// TC= O(V+E) TC of DFS
void DFS(int u, vector<list<int>>& G , vector<bool>& visited){
    visited[u]=true;
    for(int v: G[u]){
        if(!visited[v]) DFS(v,G,visited);
    }
return;
}
    int findCircleNum(vector<vector<int>>& isConnected) {

        // we just need to find the edges in connected graph 
        // hence cities are vertices now all cities in connected graph represent sing province 


      
      // its an n*n matrix 
      // so there will be total n cities 
       int n= isConnected.size(); // total rows which will be eq to cols also 
      
   

      // BUILD GRAPG first 
      vector<list<int>>G(n);
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){ 
            if(i!=j && isConnected[i][j]==1){
                G[i].push_back(j);

            }
        }
      }

// now whole builded graph we get 

vector<bool>visited(n,false);
int cnt=0;
for(int i=0;i<n;i++){
    if(!visited[i]){
        cnt++; // each DFS call from here tarverse one connected group of cities i.e province;
        DFS(i,G,visited);
    }
}

    return cnt;
        
    }
};