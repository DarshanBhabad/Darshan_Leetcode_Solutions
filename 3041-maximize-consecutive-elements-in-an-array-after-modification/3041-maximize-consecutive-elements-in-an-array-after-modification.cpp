class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
    // we will use dp + sorting 
    sort(nums.begin(),nums.end());
    int n=nums.size();
    unordered_map<int,int>dp; //will treat map as dp values or keyu when crated gets initialized with value 0
    // we store the best possible sequence in dp with ending in x dp[x] // handled teh duplicated as well
    int ans=0;
    for(int x:nums){
         dp[x+1]=dp[x]+1;  // in case of duplicates x+1 depends on x eitehr we can make ex 2,2  2=3 
         // in case of single ele as nums is sorted ex 2 
         dp[x]=dp[x-1]+1;
         // ex 1,2  2 chnaces either 1 2  or 2 3 we dont know which sequence is best and will contribute infutyure
         // 1,2,4,5,6  1,2,4,5,6  ans=3  but 2,3,4,5,6 ans=5
         ans=max(ans,max(dp[x],dp[x+1]));
    }

return ans;


//        // sort(nums.begin(),nums.end());
//        int n=nums.size();
//         map<int,int>m;
//         for(int i=0;i<n;i++){
//             m[nums[i]]++; //store the cnt of elements 
//         }
// //int will be in sorted order
// int ans=1;
//         int c=0;
//         int prev=-1;
//         int prevf=-1;
//         for(auto &p:m){
//             if(p.first!=prev+1) c=0;
            
//             if(p.first==prev+1 && prevf>1) c+=1; //its own value cnt by prev we just need to cnt next          
//             else if(p.second>1) c+=2;
            
//             prev=p.first;
//             prevf=p.second;
            
//          ans=max(ans,c);

//         }
//         return ans;

    }
};