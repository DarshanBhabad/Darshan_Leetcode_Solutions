// class Solution {
// public:
//     int minCostClimbingStairs(vector<int>& cost) {
//         //tabulation 
//         //1 data striuctire = 1d array 
//         // what to store = min cost to reah step i
//         // initialize wth least possible soution 
//     int n=cost.size();
//         vector<int>dp(n+1,-1);
//         if(n<=1) return 0; //cost to reach these steps will be 0
//         dp[0]=0;
//         dp[1]=0;
// // Bottom up - iteration  
//         for(int i=2;i<=n;i++){
//             dp[i]=min(dp[i-1]+cost[i-1],dp[i-2]+cost[i-2]);  // to go reach to current step minimal optimal cost to reach i-1 or i-2 as these are the only 2 options to reach i + cost of i-1 or i-2
//         }
//         return dp[n];
//     }
// };




class Solution {
public:

int getmincost(int n,vector<int>& dp,vector<int>& cost){
    
    if(dp[n]!=-1) return dp[n];
    //BC 
   if(n<=1) return 0; //no cost needed
   
      
      return dp[n]=min(getmincost(n-1,dp,cost)+cost[n-1],getmincost(n-2,dp,cost)+cost[n-2]);
   
}
    int minCostClimbingStairs(vector<int>& cost) {
        
        //choice 1 or 2 steps so recursion or iteration can be used now check for 2 conditions for dp 
        // overlapping subproblems - same values we have to calculate again and  again recursion tree is not linear has brances 
        // optimal substrature solving subproblems can solve our main pb

        // for index 2 we need 15 and 10 for 15 we need 10 so  overlapping subproblems 
        // optimal soln to reach prev index will halp caluclate ans for current index so optimal substrature
    
    //memoization 
    int n=cost.size();
    vector<int>dp(n+1,-1);
    return getmincost(n,dp,cost);

    }
};