class Solution {
public:
    int findMin(vector<int>& nums) {
    //     int n=nums.size();
    //     //O(n2)
    // while(nums[0]>nums[n-1]){
    //     rotate(nums.rbegin(), nums.rbegin() + 1, nums.rend());
    // }




        // return nums[0];




        //BS
       // o(logn)
        int n=nums.size();
    int st=0;
    int end=n-1;
      
        while(st<end){
            int mid=st+(end-st)/2;
            if(nums[mid]>nums[end]){
                st=mid+1;//ans is in right part of mid
            }
            else{
                end=mid;//min could also be mid so end=mid instead of mid-1 as  is in left part of mid
            }
            

        }
        return nums[st];//nums[end]
    }
};