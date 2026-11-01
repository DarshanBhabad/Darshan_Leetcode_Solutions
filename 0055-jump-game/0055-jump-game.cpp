class Solution {
public:

//DP MEMOIZATION to optimize recursion
bool jump(int i,vector<int>& nums,int n,vector<int>& dp){
    //BC
     if(i>=n) return false;
    if(dp[i]!=-1) return dp[i];
    if(i==n-1) return true;
   
    for(int j=nums[i];j>0 ;j--){
          if(jump(i+j,nums,n,dp)) return dp[i]=true;//we can reach true from these i for sure
    }
    
    return dp[i]=false;
}
    bool canJump(vector<int>& nums) {

        //lest use normal recursion 
       
        int n=nums.size();
        //willl kepp it in int only as -1 will be universal and when checked we save it as 
     //   1= true and 0=false;
         vector<int>dp(n,-1);
        return jump(0,nums,n,dp);
        
    }
};




// // RECURSION TLE = O(2^n)
// bool jump(int i,vector<int>& nums,int n){
//     //BC
//     if(i==n-1) return true;
//     if(i>=n) return false;
//     for(int j=nums[i];j>0 ;j--){
//           if(jump(i+j,nums,n)) return true;;
//     }
    
//     return false;
// }
//     bool canJump(vector<int>& nums) {

//         //lest use normal recursion 
//         int n=nums.size();
//         return jump(0,nums,n);
        
//     }
// };