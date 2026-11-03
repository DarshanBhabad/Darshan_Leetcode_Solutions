class Solution {
public:
    int minMoves(vector<int>& nums) {
        // as these is where we can increment value of any single element by 1 
        //unlike min moves 1 we have to just make other elements euql to greatest element 

int mx=INT_MIN;
for(int i=0;i<nums.size();i++){
    if(nums[i]>mx)mx=nums[i];
}
int ans=0;
for(int i=0;i<nums.size();i++){
      ans+=mx-nums[i];
}
return ans;


    }
};