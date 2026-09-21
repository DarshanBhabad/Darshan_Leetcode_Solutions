class Solution {
public:

int getcnt(int i, int n,vector<int>& dp){
    if(i==n) {
        return 1;
    }
    if(i>n) return 0;
    if(dp[i]!=0 ) return dp[i];
    //at each step it will have 2 choices climb 2 steps or climb 1step
    int one=getcnt(i+1,n,dp);
    int two=getcnt(i+2,n,dp);
    return dp[i]=one+two;

}
    int climbStairs(int n) {
        //normal recursion tle so lets use memiozation DP
        vector<int>dp(n+1,0); //as 
        
        
        return getcnt(0,n,dp);
        
    }
};