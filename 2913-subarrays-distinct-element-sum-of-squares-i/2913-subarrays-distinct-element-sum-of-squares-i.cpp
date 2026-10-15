class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int cnt;
        for(int i=0;i<n;i++){
            set<int>s;
            cnt=0;
            for(int j=i;j<n;j++){
                if(s.find(nums[j])==s.end()) cnt++; //ensures only first appreacnce is counted 
                s.insert(nums[j]); // maintaimsn unique values only 
                 ans+=cnt*cnt;
            }
           
        }
        return ans;
    }
};