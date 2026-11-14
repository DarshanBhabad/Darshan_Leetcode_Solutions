class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //KANDANE's Algorithm  O(n) , O(1)
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