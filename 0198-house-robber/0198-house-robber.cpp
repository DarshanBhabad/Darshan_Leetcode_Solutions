class Solution {
public:
//recursion gives overflow so lets use dp memoization 
int getamnt(int st,vector<int>& nums,int n,vector<int>& dp){
    //BC 
   
    if(st>=n) return 0;

    if(dp[st]!=-1) return dp[st]; //already calculated 
    //rob current house

    int fst=nums[st]+getamnt(st+2,nums,n,dp);
    // skip the curren house 
    int snd=getamnt(st+1,nums,n,dp);

return dp[st]=max(fst,snd);

}
    int rob(vector<int>& nums) {
      int n=nums.size();
        // choices as we can st from 1st house or house adjacent to it that is 2nd house 
        vector<int>dp(n+1,-1);
       
        return getamnt(0,nums,n,dp);
        
    }
};