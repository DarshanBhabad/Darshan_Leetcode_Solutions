class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        
          //TABULATION
          vector<int>dp(n+1);
          dp[0]=0;
          
          for(int i=1;i<=n;i++){
           // as i>=3 all 3 possible 1,2,3 
               dp[i]=dp[i-1]+costs[i-1]+1;
               if(i >= 2)
                dp[i] = min(dp[i],
                            dp[i-2] + costs[i-1] + 4);
              if(i>=3)
              dp[i]=min(dp[i],dp[i-3]+costs[i-1]+9);
          }


return dp[n];



    }
};






// class Solution {
// public:

// memoization TLE as more recurevie calls 
// int getcost(int n,vector<int>&dp,vector<int>& costs){
//     if(n==0) return 0;
//     if(dp[n]!=-1) return dp[n];//already calculated 
//     if(n==1) return dp[n]=costs[n-1]+1; //stnep i to step j is defined as: costs[j] + (j - i)2 sub i=0;
//     if(n==2) return dp[n]=min(costs[n-1]+4,getcost(1, dp, costs) + costs[n-1] + 1);  //(1st way = 2steps directly, 1 step at a time )
    

    
//     return dp[n]=min({getcost(n-1,dp,costs)+costs[n-1]+1,getcost(n-2,dp,costs)+costs[n-1]+4,getcost(n-3,dp,costs)+costs[n-1]+9});  //jump n-1 to 1 j-i=1 , n-2 to n j-i=2  , n-3 to n j-i=3   no need to calulate other ways ways from n-2 to n  as they ultimatey take us to n-1 which alredy has ooptimal solution in dp

//     //costs[i] is o index based so to get cost of n we need to access index n-1;

// }
//     int climbStairs(int n, vector<int>& costs) {
//         //memozation dp 
//         //recusrsion + strorage 
//         //dp will store the optimal cost to reach curret step
//         //start from step 0;
//         vector<int>dp(n+1,-1);
//         return getcost(n,dp,costs);
//     }
// };

//another version ;
// class Solution {
// public:
//     int getcost(int n, vector<int>& dp, vector<int>& costs) {
//         if(n == 0) return 0;

//         if(dp[n] != -1)
//             return dp[n];

//         // jump 1 step
//         int one = getcost(n-1, dp, costs)
//                   + costs[n-1] + 1;

//         // jump 2 steps possible only when cusrrently n is greater than or equal to 2

//// recurrence is costs[j]+(j−i)2  so we calculated base cases manually 




//         int two = INT_MAX;
//         if(n >= 2)
//             two = getcost(n-2, dp, costs)
//                   + costs[n-1] + 4;

//         // jump 3 steps
//         int three = INT_MAX;
//         if(n >= 3)
//             three = getcost(n-3, dp, costs)
//                     + costs[n-1] + 9;

//         return dp[n] = min({one, two, three});
//     }

//     int climbStairs(int n, vector<int>& costs) {
//         vector<int> dp(n+1, -1);
//         return getcost(n, dp, costs);
//     }
// };
