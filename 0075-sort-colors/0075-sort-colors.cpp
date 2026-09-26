class Solution {
public:
    void sortColors(vector<int>& nums) {
        //Bubble sort 
int n=nums.size();
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]<=nums[i])
                swap(nums[i],nums[j]);
            }
        }
        return ;
    }
};