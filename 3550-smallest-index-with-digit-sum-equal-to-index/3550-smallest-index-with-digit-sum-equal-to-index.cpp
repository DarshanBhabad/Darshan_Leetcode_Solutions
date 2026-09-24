class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++){
            int a=nums[i];
            sum=0;
            while(a!=0){
                sum+=a%10;
                a/=10;
            }
            if(sum==i) return i;

        }
        return -1;
    }
};