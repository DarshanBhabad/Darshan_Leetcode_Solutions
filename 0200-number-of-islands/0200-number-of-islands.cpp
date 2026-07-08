class Solution {
public:
//TC=O(V+E) //vertices will be cells with val '1' and edges betn them

void dfs(int i, int j , vector<vector<bool>>& visited,vector<vector<char>>& grid,int m,int n ){
    //BC
    if(i>=n||j>=m||i<0||j<0||grid[i][j]=='0'||visited[i][j]){
        return;
    }
    visited[i][j]=true;
 //now each valid vertices will have 4 neighbours up,down,right and left.....diagonal not applicable
  dfs(i-1,j,visited,grid,m,n); //top neigh
  dfs(i,j+1,visited,grid,m,n); //right neigh
  dfs(i+1,j,visited,grid,m,n); //bottom neigh
  dfs(i,j-1,visited,grid,m,n); //left neigh
  return;

}
    int numIslands(vector<vector<char>>& grid) {
        int islands=0;
        int n=grid.size(); //rows
        int m=grid[0].size(); //cols
        vector<vector<bool>>visited(n,vector<bool>(m,false)); //visited bool 2D array initialized with false values for each cell;

        // consider it as disconnected graph and each  component of it will act as island
        // also to get diff components we have to consider diff sources as from single source we can't cover whole graph
        // travel each cell
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j]=='1') { //if not visited and grid value is 1
                dfs(i,j,visited,grid,m,n);  // each call will mark one component of disconnected grapth or one island
                islands++;


                }
            }

        }


return islands;
        
    }
};