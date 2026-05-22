class Solution {
public:

    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int st=0;
        int end=n-1;
        
        while(st<=end){
            int mid=(st + (end-st)/2);
            if(nums[mid]==target)
            return mid;
           
    
            if(nums[st]<=nums[mid]){                                //left part is sorted
              if(nums[st]<= target && target<nums[mid])  //BS in Left part
              end=mid-1;
              else
              st=mid+1;

            }

            else{   //right part is sorted
            if(nums[mid]<target && target<=nums[end]) //BS in Right Part
            st=mid+1;  
            else
            end=mid-1;

            }
        }
        return -1;

        
        
    }
};