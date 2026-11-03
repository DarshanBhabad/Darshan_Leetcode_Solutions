class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>p;

        vector<int>ng;
        for(int i=0;i<n;i++){
            if(nums[i]>0) p.push_back(nums[i]);
            else ng.push_back(nums[i]);
        }
int k=0;
int l=0;
        for(int i=0;i<n;i++){
             if(i%2==0){
                nums[i]=p[k];
                k++;
             }  
             else {
                nums[i]=ng[l];
                l++;
             }
        }
        return nums;
    }
};