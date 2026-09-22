class Solution {
public:
int getfib(int n,vector<int>& dp){
    if(dp[n]!=-1) return dp[n]; //it will saves calls for n<=1 as once they calculated we are going to store them
    if(n<=1) {
        dp[n]=n;
        return n;
    }
    
    return dp[n]=getfib(n-1,dp)+getfib(n-2,dp);
}
    int fib(int n) {
        //memoization 
        vector<int>dp(n+1,-1);
        return getfib(n,dp);
        
    }
};