class Solution {
public:

int getnthterm(int n,vector<int>& dp){
    //top down ...choices...recursion
    if(n==0) return 0;
    if(n<=2) return 1;
    if(dp[n]!=-1) return dp[n];

    return dp[n]= getnthterm(n-1,dp)+getnthterm(n-2,dp)+getnthterm(n-3,dp);
}
    int tribonacci(int n) {
        //suing the dp( memoization)
        vector<int>dp(n+1,-1);
        return getnthterm(n,dp);
        
    }
};