class Solution {
public:
//TC=O(n2) can also go with recursion dp which is smae tc  but only recursion is 2^n
    int jump(vector<int>& nums) {
        //we will use bottom up dp 
        //data stractur ew 1D dp
        // min num,ber of jumps  to reach current step/imndex
        // base case 1st index jumps = 0
int n=nums.size();
        vector<int>dp(n,INT_MAX);
        dp[0]=0;
        if(n==1) return 0; //we alredy stert here 
         dp[1]=1;
        for(int i=2;i<n;i++){
            for(int j=0;j<i;j++){

           if(nums[j]+j>=i){
                dp[i]=min(dp[i],dp[j]+1); // steops to reach j and from j to i we need one jump as it is reachble and in range so dp[j]+1
           }
            }

        }
return dp[n-1];
    }
};

// GREEDY TC=O(n) SC=O(1)
// class Solution {
// public:
//     int jump(vector<int>& nums) {
//         int currentreach = 0;
//         int currentMax = 0;
//         int jump=0;
//         int n =nums.size();
//         for(int i=0;i<n-1;i++){
//         if(i+nums[i]>currentMax){
//             currentMax = i+nums[i];
//         }

//         if (i==currentreach){
//             jump++;
//             currentreach= currentMax;
//         }
//         }

//         return jump;
        
//     }
// };