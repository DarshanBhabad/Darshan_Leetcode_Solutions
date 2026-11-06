class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       // optimized -> O(n)
       int n=nums.size();
unordered_map<int,int>m;
for(int i=0 ;i<n;i++){
    m[nums[i]]=i ; // if tehre are duplicate elemnets it will ahve last occurence index 
}

for(int i=0;i<n;i++){
    int c=target-nums[i];
    if(m.find(c)!=m.end() && m[c]!=i)//duplication handeled  see test case 3
    {
        return {i,m[c]};
    }
}
    return {-1,-1};






    //   //brute force n2
    //   for(int i=0;i<nums.size();i++){
    //     for(int j=i+1;j<nums.size();j++){
    //         if(nums[i]+nums[j]==target) return {i,j};
    //     }
    //   }
    //   return {-1,-1};
    }
};