class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // The maximum product can either be from:
        // - The three largest numbers
        // - The two smallest numbers and the largest number
        int n=nums.size();
        int maxprod=INT_MIN;
        sort(nums.begin(),nums.end());
        maxprod=max(nums[n-1] * nums[n-2] * nums[n-3], nums[0] * nums[1] * nums[n-1]);
        return maxprod;
    }
};