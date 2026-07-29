class Solution {
public:

bool issorted(vector<int>&nums){
      //check if sorted 
      
       for(int i=0;i<nums.size()-1;i++){
        if(nums[i]>nums[i+1]) {
           return false;
       }

}
 return true; //already sorted

       //find the pos of minsum 

}

int minpair(vector<int>&nums){
    int minsum=INT_MAX;
    int pos=-1;
    for(int i=0;i<nums.size()-1;i++){
        if(nums[i]+nums[i+1]<minsum){
            minsum=nums[i] + nums[i + 1];
            pos=i;
        }
    }
    return pos;
}

void mergepair(vector<int> &nums, int pos){
    nums[pos]+=nums[pos+1];
    nums.erase(nums.begin() + pos + 1) ; //v.erase(v.begin() + pos + 1); removes a single element at index pos + 1
}

int minimumPairRemoval(vector<int>& nums) {

int ops=0;
while(!issorted(nums)){ //while nums get sorted
  mergepair(nums,minpair(nums)); //minpair gives pos where merge should be placed
  ops+=1;  //



}
      

 return ops;    
    }
};