class Solution {
public:

void DFS(int i,vector<list<int>>& G,vector<bool>& vis,int & cnt){
    cnt++;
   vis[i]=true;
   for(int v:G[i]){
     if(!vis[v]) {
        
      DFS(v,G, vis, cnt);

   }
   }
}
    int maximumDetonation(vector<vector<int>>& bombs) {
      int n=bombs.size();
      //DFS for SURE because one in detonatiing otehr so chain is forming
//longest connected component
//build a directed graph where i -> j if bomb i can detonate bomb j, then run DFS from every bomb and take the maximum number of visited bombs.
  vector<list<int>>G(n);
  //BUILD NEIGHBOURS 
 // (xi​−xj​)2+(yi​−yj​)2≤ri2​ (xi,yi) -> (xj,yj)  ....circles intersect only if tehs econdition holds 
 
  // we can run DFS from every bomb  ... Treating bombs as vertices 
  /// and bomb having  most b=neighbours or components is the ount we needed 



 
  for(int i=0;i<n;i++){//to tavers eall components oin case there are multiple compos
    // for(int j=0;j<3;j++)
   long long x1 = bombs[i][0];
   long long y1 = bombs[i][1];
   long long r1 = bombs[i][2];
   for(int j=0;j<n;j++){
    if(i==j)continue;
    long long x2 = bombs[j][0];
    long long y2 = bombs[j][1];

    long long dx = x1 - x2;
    long long dy = y1 - y2;
    if(dx * dx + dy * dy <= r1 * r1) {
     G[i].push_back(j); // push_neighbour;
      }

   }

  }
  int mcnt=0;

  // now move for dfs for each bomb to cover all components 
     for(int i = 0; i < n; i++) {

        vector<bool> vis(n, false);
        int cnt = 0;
        DFS(i, G, vis, cnt);
        mcnt = max(mcnt, cnt);
    }


 

return mcnt;
    }
};