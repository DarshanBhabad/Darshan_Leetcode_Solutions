class Solution {
public:
    bool check(vector<int>& nums) {
        // int cnt=0;
        // int n=nums.size();
        // vector<int>a(nums);
        // sort(a.begin(),a.end());
        // for(int i=1;i<nums.size();i++){
        // if(nums[i-1]>nums[i]){
        //     cnt=i;
        //     break;
        // }
        
            
        // }
        // int x=n-cnt;
        // for(int i=0;i<n;i++){
        //     if(nums[i]!=a[(i+x) % n])
        //     return false;
        // }



        // return true;

        // #INVERSION COUNT APPROACH as array is rotated there will be an index where nums[i-1]>nums[i]
        // if not roatted same as sorted no inversions so initail cnt is 0
        //also consider edge case where we have middle elements sorted and inversion is at start
        //ex. [2,1,3,4] but we have to check 1st and last element as last ele should be less than st
        //as array is left rotated st ele goed to end so new st is biggger that end 

        int cnti=0; //inversion cnt
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                cnti++;
                if(cnti>1) return false;
            }
        }
        //edge case
        if(nums[0]<nums[n-1]) cnti++;

        return cnti<=1;//return true if cnt is 0 || 1 else false 
    }
};