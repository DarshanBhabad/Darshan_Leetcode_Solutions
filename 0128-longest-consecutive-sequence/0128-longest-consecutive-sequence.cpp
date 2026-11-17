class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //o(nlogn)
          int n=nums.size();
          if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int ans=1;
        int cnt=1;
        //handle duplicates 
        for(int i=1;i<n;i++){
               if(nums[i]-nums[i-1]==1) cnt++;
               else if(nums[i]==nums[i-1]) continue; //dont change or ereset count
               else{
               
                cnt=1;
               } 
               ans=max(ans,cnt);
        }
        
        return ans;
    }
};