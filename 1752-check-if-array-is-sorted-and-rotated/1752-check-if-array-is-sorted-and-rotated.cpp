class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        vector<int>a(nums);
        sort(a.begin(),a.end());
        for(int i=1;i<nums.size();i++){
        if(nums[i-1]>nums[i]){
            cnt=i;
            break;
        }
        
            
        }
        int x=n-cnt;
        for(int i=0;i<n;i++){
            if(nums[i]!=a[(i+x) % n])
            return false;
        }



        return true;
    }
};