class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        //2 pntr  sliding window
        
        int n=nums.size();
        if(n==1) return 1;
        int i=0;
        // j=1;
        // int ans=1;
        // bool a=true;
        int ans=1;
        int j=0;
       
        // while(j<n){
               
            
            
        // }
        bool t=true;
        bool d=true;
int cnti=1;
int cntd=1;
for(int i=1;i<n;i++){
    if(nums[i]>nums[i-1]) {
        cnti++;
        cntd=1;
        ans=max(ans,cnti);
    }
    if(nums[i]<nums[i-1]) {
       cntd++;
       cnti=1;
       ans=max(ans,cntd);
    }
    if(nums[i]==nums[i-1]) {
       cntd=1;
       cnti=1;
       
    }
    
}
return ans;

    }
};