class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //each day index wills store the max profit upto  that point
        //not complete but somewhat dp
        int n=prices.size();
        if(prices.size()<1) return 0;
        vector<int>dp(n);
        dp[0]=prices[0];  
        int ans =0;
        for(int i=1;i<n;i++){
            dp[i]=min(dp[i-1],prices[i]);//minimum value  seen upto current index
            ans=max(ans, prices[i]-dp[i-1]); //current prices - min price seen so far
        }
return  ans; //max profit 
// Tc=O(n);
    }
};