class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int n=nums.size();
        
      // as we have to create pairs each time we see wee need min of 2 elements does'nt matter which pair we going to get we will select min
      // so too maximize result
      // so sort the nums and select the alternate element 1 2 3 4 = 1 + 3 =4
      // (1,3)(1,2)(1,4) always have min =1 similarly otehrs , so to maximize choose alternate
      // we have to devide array to n pairs and choose optimal pair of all combinations
      sort(nums.begin(),nums.end());
        int sum=0;
        for(int i=0;i<n;i+=2){
            sum+=nums[i];

        }
        return sum;
    }
};