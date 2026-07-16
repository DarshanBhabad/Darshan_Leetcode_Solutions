class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        if(nums.size()==1) return 0;
        vector<int>pregcd;
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++){
            maxi=max(maxi,nums[i]);
            pregcd.push_back(gcd(nums[i],maxi));
        }
        sort(pregcd.begin(),pregcd.end());
        int i=0;
        int j=pregcd.size()-1;
        long long sum=0;
        while(i<j){
            sum+=gcd(pregcd[i],pregcd[j]);
            i++;
            j--;
        }
        return sum;
    }
};