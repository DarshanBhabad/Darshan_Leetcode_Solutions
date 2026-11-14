class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //KANDANE's Algorithm  O(n) , O(1)


// How It Works

// Instead of checking every possible combination, the algorithm scans the array once from left to right. At each number, it makes a simple local decision:

// • Extend or Restart. Decide whether adding the current number to the previous running sum makes it larger, or if starting fresh at the current number is better.

// • Discard Negative Prefixes. If the running sum ever drops below zero, carrying it forward will only reduce future sums, so it gets dropped in favor of starting a new subarray.

// • Track the Global Best. Compare the current subarray sum against the highest sum seen so far and update the record whenever a new peak is reached
        int n=nums.size();
        int ans=INT_MIN; //globbal ans
        int currentsum=0;
        for(int i=0;i<n;i++){
            currentsum+=nums[i];
              ans=max(ans,currentsum);
              if(currentsum<0) {
                   
                currentsum=0;
              }
              
        }
       
        return ans;

        //BRUTE FORCE 
        // int ans=INT_MIN;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     int sum=0;
        //     for(int j=i;j<n;j++){
        //         sum+=nums[j];
        //         ans=max(ans,sum);
        //     }
        // }
        // return ans;
    }
};