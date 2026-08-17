class Solution {
public:
 void DFS(vector<vector<int>>& grid,int i,int j,vector<vector<bool>>& visited,int &cnt,int m,int n){
    visited[i][j]=true;
    cnt++;
    int dr[4]={-1,1,0,0};
   int  dc[4]={0,0,1,-1}; //for row and col combination check adjacent to current cell i.e neighbours f current cell
    for(int k=0;k<4;k++){
        int nr=i+dr[k];
        int nc=j+dc[k];
        if(nr<m && nr>=0 && nc<n && nc>=0 && grid[nr][nc]==1&& !visited[nr][nc])//valid row and col i.e valid cell
        {
            DFS(grid,nr,nc,visited,cnt,m,n);

        }
    }

return ;

 }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //USE DFS 
        // for all components 

        int m=grid.size();
        int n=grid[0].size();
        int mcnt=0;
        int cnt;
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && !visited[i][j]){
                    cnt=0;
                    DFS(grid,i,j,visited,cnt,m,n);
                    mcnt=max(cnt,mcnt);


                }
            }
        }
return mcnt;
    }
};