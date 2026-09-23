class Solution {
public:
    int rob(vector<int>& nums) {
        //TABULATION - BOTTOM UP 
        // 1 data structure = 1D array 
        // 2 what to store = maximum  amnt upto current step 
        //3 initialize with  smallest ans 
int n=nums.size();
        vector<int>dp(n+1,-1);
        if(n == 0) return 0;
        if(n == 1) return nums[0];
        dp[0]=nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++) {
            dp[i] = max(
                dp[i-1],             // Skip current house
                nums[i] + dp[i-2]    // Rob current house
            );
        }

return dp[n-1]; // maximum amount upto currentt point consideringa ll cases including current house exclusing current house 
        
    }
};

//MEMOIZATION - TOP DOWN

// build simple recursive solution then only apply dp

// class Solution {
// public:
// //recursion gives overflow so lets use dp memoization 
// int getamnt(int st,vector<int>& nums,int n,vector<int>& dp){
//     //BC 
   
//     if(st>=n) return 0;

//     if(dp[st]!=-1) return dp[st]; //already calculated 
//     //rob current house

//     int fst=nums[st]+getamnt(st+2,nums,n,dp);
//     // skip the curren house 
//     int snd=getamnt(st+1,nums,n,dp);

// return dp[st]=max(fst,snd);

// }
//     int rob(vector<int>& nums) {
//       int n=nums.size();
//         // choices as we can st from 1st house or house adjacent to it that is 2nd house 
//         vector<int>dp(n+1,-1);
       
//         return getamnt(0,nums,n,dp);
        
//     }
// };