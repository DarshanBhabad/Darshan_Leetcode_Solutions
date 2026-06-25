class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
 int half;
 int ans=0;
 unordered_map<int,int>m;
        for(int i=0;i<n;i++){
             m[target]=0;
            for(int j=i;j<n;j++){
                
                if(nums[j]==target){
                    m[nums[j]]++;
                }
                half=(j-i+1)/2;
                if(m[target]>half) ans++;
                
            }
           
        }
        return ans;
    }
};