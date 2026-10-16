class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //unordered_set<int>s;
        
int n=nums.size();
if(n==0) return 0;
        int j=0;
        int cnt=1;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[j]){
                j++;
                cnt++;
                swap(nums[j],nums[i]);
            }
        }

return cnt;
    }
};