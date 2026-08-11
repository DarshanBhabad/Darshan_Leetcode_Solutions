class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        unordered_set<int>s;
        int n=nums.size();
        int mine=INT_MAX;
        int maxe=INT_MIN;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);// set mantains only unique values
            if(nums[i]>maxe) maxe=nums[i];
            if(nums[i]<mine)  mine=nums[i];


        }
        vector<int>ans;
        for(int i=mine;i<=maxe;i++){
            if(s.find(i)==s.end()) ans.push_back(i);
        }
        return ans;
    }
};