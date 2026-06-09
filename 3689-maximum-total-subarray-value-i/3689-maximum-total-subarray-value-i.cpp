class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size(); 
        //as we can choose given sbarray k gtimes also , so we just have to choose subarray having 
        // diff betn min and max most ... no need to do combinations as choosing let k=3 
        // choosing 2 with 6 and 1 subarray with value 4 result=16 ,,.. but we can choose max k times also so result=6*6*6 =18;
        if(n==1) return 0; // (k*(number-number)=0) //as min=max

         int min_e=nums[0];
         int max_e=nums[0];
        long long total_val=0;
        long long curr_val;

        for(int i=1;i<n;i++){
            if(nums[i]>max_e){
               // min=max;
                max_e=max(max_e,nums[i]);
                
            }
            if(nums[i]<min_e){
                min_e=min(min_e,nums[i]);
            }
            curr_val=1LL*(max_e-min_e)*k;
            total_val=max(total_val,curr_val);


        }
        return total_val;
    }
};