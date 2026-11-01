class Solution {
public:
//v=n*m so TC =O(v+e)= O(n*m);
void DFS(int u,int v,vector<vector<int>>& grid,vector<vector<bool>>& vis,int n,int m, long long &sum){
    vis[u][v]=true;
    sum+=grid[u][v];
    //space optimization  grid[u][v] = -1;    // Mark as visited
    int dr[]={1,-1,0,0};
    int dc[]={0,0,-1,1};
    //explore all four neighbours
    for(int i=0;i<4;i++){
        int nr=u+dr[i];
        int nc=v+dc[i];
        if(nr>=0 && nc>=0 && nr<n && nc<m && !vis[nr][nc] && grid[nr][nc]!=0) DFS(nr,nc,grid,vis,n,m,sum);
    }
    return;
}
    int countIslands(vector<vector<int>>& grid, int k) {
        ///again same dfs approach
        int n=grid.size();
        int m=grid[0].size();
        //or spacew optimization just put visited cells to -1
        long long sum;
        int cnt=0;
     vector<vector<bool>>vis(n,vector<bool>(m,false));
     //to explaore all possible connected components or graphs
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                //component 
                 if(!vis[i][j] && grid[i][j]!=0){
                    sum=0;
                    DFS(i,j,grid,vis,n,m,sum);
                    if(sum%k==0) cnt++;
                 }
            }
        } 
        return cnt;
    }
};