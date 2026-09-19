class Solution {
public:

int getpathcnt(int i,int j, int m,int n,vector<vector<int>>& dp,vector<vector<int>>& obstacleGrid){
    if(i>m-1 || j>n-1 || obstacleGrid[i][j]==1) return 0;
    if(i==m-1 &&j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];

    int right=getpathcnt(i,j+1,m,n,dp,obstacleGrid);
    int down=getpathcnt(i+1,j,m,n,dp,obstacleGrid);
    dp[i][j]=right+down;
    //dp[i][j]=dp[i+1][j]+dp[i][j+1];
    return dp[i][j];
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();

        int cnt=0;
    vector<vector<int>>dp(m,vector<int>(n,-1));

        return getpathcnt(0,0,m,n,dp,obstacleGrid);
    }
};