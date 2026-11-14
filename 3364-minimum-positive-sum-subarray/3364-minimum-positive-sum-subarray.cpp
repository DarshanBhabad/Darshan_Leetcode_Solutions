class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n=nums.size();
        if(n<l) return -1;
        //all subarrays 
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int sum=0;
            for(int j=i;j<n;j++){ //subarrays starting from i; 
            int size =j-i+1; 
            sum+=nums[j];
                        if(size>=l && size<=r)    //j-i+1 => size 
                        {
                            if(sum>0) ans=min(ans,sum);
                        }
            }
        }
if(ans==INT_MAX) return -1;
        return ans;
    }
};