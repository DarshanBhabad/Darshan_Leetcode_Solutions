class Solution {
public:
    int findGCD(vector<int>& nums) {
        // int minNum = *min_element(nums.begin(), nums.end()); // Find the smallest number
        // int maxNum = *max_element(nums.begin(), nums.end()); // Find the largest number

        // return gcd(minNum, maxNum); // Calculate the GCD of min and max

        int minn=INT_MAX;
        int maxn=INT_MIN;
        for(int i=0;i<nums.size();i++){
            minn=min(nums[i],minn);
            maxn=max(nums[i],maxn);

        }
        return gcd(minn,maxn);
    }
};