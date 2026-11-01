class Solution {
public:
//tc = O(n*m*1024) // xor can exceed 1023  0 <= grid[i][j] <= 1023​
int paths(int i, int j, vector<vector<int>>& grid,
              vector<vector<vector<int>>>& dp,
              int n, int m, int tans){
    //boundry conditions 
    if(i<0 || j<0 || i>=n || j>=m ) return INT_MAX; //bndry condiytion falied
    //BC for ans
    tans^=grid[i][j];
    if(dp[i][j][tans]!=-1) return dp[i][j][tans]; // upto current cell if we have same xor as computedsomwhere alredy satet founfd so it definitely that it willl be same as alredy clalculated so no need to explore  paths again 

//incase new path or path having different xor as compueted earlier new sate
    if(i==n-1 && j==m-1) {
       return dp[i][j][tans]=tans;
    }
   
   int left= paths(i,j+1,grid,dp,n,m,tans); //right
    int right=paths(i+1,j,grid,dp,n,m,tans);  //down tans willl have xor ciomputed upto taht cell as we pass it with referencing it
     return dp[i][j][tans]=min(left,right);
     //in final ans we return min with storing it in dp[0][0][0] //1st cell
  
 
}
    int minCost(vector<vector<int>>& grid) {
        //recursion
        int n=grid.size();
        int m= grid[0].size();
        //  int ans=INT_MAX;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m, vector<int>(1024, -1)));
        //n*m*1024 size vector
        //3 dp state variable scell and xor calculated 
        //for same cell there can be different paths i.e different xor's calculated 
         int tans;
        return paths(0,0,grid,dp,n,m,0);
   
    }
};


//RECURSION

// class Solution {
// public:
// //tc using recursion is number of paths from src to dest
// void paths(int i,int j,vector<vector<int>>&grid,int n,int m,int &ans,int tans ){
//     //boundry conditions 
//     if(i<0 || j<0 || i>=n || j>=m ) return; //bndry condiytion falied
//     //BC for ans
//      tans^=grid[i][j];
//     if(i==n-1 && j==m-1) {
//         ans=min(ans,tans);
//         return;
//     }
   
//     paths(i,j+1,grid,n,m,ans,tans); //right
//     paths(i+1,j,grid,n,m,ans,tans);  //down tans willl have xor ciomputed upto taht cell as we pass it with referencing it
//     return;
// }
//     int minCost(vector<vector<int>>& grid) {
//         //recursion
//         int n=grid.size();
//         int m= grid[0].size();
//          int ans=INT_MAX;
//          int tans;
//         paths(0,0,grid,n,m,ans,0);
//         return ans;
//     }
// };