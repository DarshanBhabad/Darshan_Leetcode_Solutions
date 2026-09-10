class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i=0;
        //sort(nums.begin(),nums.end());
        unordered_map<int,int>m; //as each element will appear only once we store element and its index
     int n=nums.size();
        // int sum=0;
        for(int i=0;i<n;i++){
             m[nums[i]]=i;
        }    
        for(int i=0;i<n;i++){
            if(m.find(target-nums[i])!=m.end()&&m[target-nums[i]]!=i){
                return{i,m[target-nums[i]]};
            }
        }
        return{-1,-1};
        // //
        // vector<int> twoSum(vector<int>& nums, int target) {
        // std::unordered_map<int, int> numbers;

        // for(int i=0; i<nums.size(); ++i){
        //     int complement = target - nums[i];

        //     if(numbers.find(complement) != numbers.end()){
        //         return {numbers[complement], i};
        //     }

        //     numbers[nums[i]] = i;
        // }

        // return {};
    }
};