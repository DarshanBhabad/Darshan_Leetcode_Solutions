class Solution {
public:
//BY TABULATION
// 1. DS= array 1D 
//2 what to store = no of distinct ways  needed to reach i 
//3 initialize with smallest possible ans dp[0]=0 dp[1]=1 
// if n=0 no steps needed n=1 1 step only 
// n=2  ans=1+1(two small steps) or ans=2 (single step 2 length big )
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        vector<int>dp(n+1,0);
        dp[0]=0; // not necessary but 
        dp[1]=1; //base cases 
        dp[2]=2; 

        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]; // i-2 willl contibute with 2 ways to reach i and i-1 with only 1 way so add their count 
        }
//         There is exactly 1 possible jump from stair 2 to stair 4: a jump of 2 steps.

// So, for every way of reaching stair 2, we take that extra jump. =  dp[2] * 1 ways to reach 2 * from 2 to 4 ( which eactly one way i.e jump of 2 ) 

return dp[n];
     

       
    }
};

//         class Solution {
// public:

// int getcnt(int i, int n,vector<int>& dp){
//     if(i==n) {
//         return 1;
//     }
//     if(i>n) return 0;
//     if(dp[i]!=0 ) return dp[i];
//     //at each step it will have 2 choices climb 2 steps or climb 1step
//     int one=getcnt(i+1,n,dp);
//     int two=getcnt(i+2,n,dp);
//     return dp[i]=one+two;

// }
//     int climbStairs(int n) {
//         //normal recursion tle so lets use memiozation DP
//         vector<int>dp(n+1,0); //as 
        
        
//         return getcnt(0,n,dp);
        
//     }
// };
 