class Solution {
public:
    int countConsistent(vector<int>& nums) {
       
        int n=nums.size();
        int c=0;
        for(int i=0;i<nums.size();i++){
            int a=-1; //all bits set to 1 makes it identity for bitwise operations 
             int m=INT_MAX;
            for(int j=i;j<n;j++){
                a&=nums[j];
                m=min(nums[j],m);
                if(a==m) c++;
            }
        }
        return c;
    }
};