class Solution {
public:

// You don't need to explore the same cell repeatedly.

// For every cell, the number of paths to the destination is:

// paths(i,j)=paths(i,j+1)+paths(i+1,j)

// as dp[i][j] will store all the possible paths from the given cell 
// so it will avoid teh problem we gfaced in pur recursion method where we count the cell again for the same paths it already given for another previous call // instead store it 
     int getallpaths(int i, int j, int m, int n,
                    vector<vector<int>>& dp) {

        if(i >= m || j >= n) return 0;

        if(i == m-1 && j == n-1) return 1;

        if(dp[i][j] != -1) return dp[i][j]; // directly return the stored count dp[i][j] willl be count of all possible valid paths from cell

        int right = getallpaths(i, j+1, m, n, dp);
        int down = getallpaths(i+1, j, m, n, dp);
      
        return dp[i][j] = right + down;  
        //or dp[i][j]=right+down;
        //return dp[i][j];
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return getallpaths(0, 0, m, n, dp);
    }
};
        
// class Solution {
// public:

// // correct resursion solution but you have to use dp here to avoid tle error
// void getallpaths(int i,int j,int m,int n,int &cnt){
//     if(i<0 || j<0||i>m-1||j>n-1) return;//invalid path
//     if(i==m-1 && j==n-1) { //got path
//      cnt++;
//      return; //return so to get anotehr possible path
//     }
//     getallpaths(i,j+1,m,n,cnt);//all possible paths by taking right choice from current 
//     getallpaths(i+1,j,m,n,cnt);//all possible paths by taking  down choice from current
// return;
  
// }
//     int uniquePaths(int m, int n) {

//         int cnt=0;
//         getallpaths(0,0,m,n,cnt);
//         return cnt;
//     }
// };

