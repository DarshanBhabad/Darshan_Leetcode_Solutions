class Solution {
public:
int getpathcnt(int i,int j, int m,int n,vector<vector<int>>& dp,vector<vector<int>>& grid){
    //BC = when to stop recursion 
    if(i>=m || j>=n ) return INT_MAX;//invalid path
    //valid path found =destination 
    if(i==m-1 &&j==n-1) return grid[i][j];
    //already calculated 
    if(dp[i][j]!=INT_MAX) return dp[i][j];
      

    int right=getpathcnt(i,j+1,m,n,dp,grid);
    
    int down=getpathcnt(i+1,j,m,n,dp,grid);
    
    int best=min(right,down);
    
        // Avoid adding to INT_MAX //both paths were invalid so best  return  INT_MAX 
        if (best == INT_MAX) //dp[i][j]=best  return dp[i][j]
            return dp[i][j] = best;


    dp[i][j] = grid[i][j] + best; //best path from down and right 
    return dp[i][j];
}

    int minPathSum(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
     
        
    vector<vector<int>>dp(m,vector<int>(n,INT_MAX));

        return getpathcnt(0,0,m,n,dp,grid);
    }
};