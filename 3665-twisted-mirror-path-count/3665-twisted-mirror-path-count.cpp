class Solution {
public:
//DP + recursion 

  const int MOD = 1e9 + 7;

 vector<vector<vector<int>>> dp;
//memoizing only the non-mirror cells.
int getpaths(int i,int j,vector<vector<int>>& grid,int n,int m,int dir){
    //dir in which we entered teh current cell is dir
    if(i<0 ||j<0||i>=n ||j>=m) return 0; //invalid don't count
    if(i==n-1 && j==m-1){
       
        return 1; //count 
    }

     if(dp[i][j][dir] != -1)
            return dp[i][j][dir];

    if(grid[i][j]==1){//mirror
         if (dir == 0)    return getpaths(i + 1, j, grid,  n, m, 1);  // came right -> go down  //0 =right 1=down 
        else         return    getpaths(i, j + 1, grid,  n, m, 0);  // came down  -> go right soset gpoing dir =0
     
    }
   

   
   long long ans=0;
  // empty cell (or start): free choice
    ans+=getpaths(i, j + 1, grid,  n, m, 0);           // right
    ans+= getpaths(i + 1, j, grid,  n, m, 1);           // down

return dp[i][j][dir]=ans%MOD; //count of possible solution fromc yurrent position 
}


bool check(int i, int j, int n,int m,vector<vector<int>>& grid){
    if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1 ) return true ;
    return false; 
}
    int uniquePaths(vector<vector<int>>& grid) {
        //RECUSRSION AND DP 
        int n=grid.size();
        int m=grid[0].size();
    int cnt=0;
     dp.assign(n, vector<vector<int>>(m, vector<int>(2, -1))); // 2 values 0,1
     //Same (i,j), but different dir means different results.
     // dp anwers for right oth col and for down 1st col we store two values for each  cell
     //coming from rigth and w=don
    
  return  getpaths(0,0,grid,n,m,0); //Since the starting cell is empty, pass either direction as the initial state:

    }
};



//RECURSION  - Exponnetial
// class Solution {
// public:

// void  getpaths(int i,int j,vector<vector<int>>& grid,int &cnt,int n,int m,int dir){
//     //dir in which we entered teh current cell is dir
//     if(i<0 ||j<0||i>=n ||j>=m) return; //invalid don't count
//     if(i==n-1 && j==m-1){
//         cnt++;
//         return;
//     }
//     if(grid[i][j]==1){//mirror
//          if (dir == 0) getpaths(i + 1, j, grid, cnt, n, m, 1);  // came right -> go down  //0 =right 1=down 
//         else          getpaths(i, j + 1, grid, cnt, n, m, 0);  // came down  -> go right soset gpoing dir =0
//         return;
//     }
   

   
   
//   // empty cell (or start): free choice
//     getpaths(i, j + 1, grid, cnt, n, m, 0);           // right
//     getpaths(i + 1, j, grid, cnt, n, m, 1);           // down

// return;
// }


// bool check(int i, int j, int n,int m,vector<vector<int>>& grid){
//     if(i>=0 && j>=0 && i<n && j<m && grid[i][j]==1 ) return true ;
//     return false; 
// }
//     int uniquePaths(vector<vector<int>>& grid) {
//         //RECUSRSION AND DP 
//         int n=grid.size();
//         int m=grid[0].size();
//     int cnt=0;
    
//     getpaths(0,0,grid,cnt,n,m,-1); //initially -1
// return cnt;
//     }
// };