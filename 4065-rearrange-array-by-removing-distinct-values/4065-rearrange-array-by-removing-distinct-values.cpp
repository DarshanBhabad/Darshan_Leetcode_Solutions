class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        map<int,int>m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        //all values are added in sorted order with there frq;
        vector<int>ans;
        while(!m.empty()){
             for(auto it = m.begin(); it != m.end(); ) {
                ans.push_back(it->first);
                it->second--;

                if(it->second == 0) {
                    it = m.erase(it);
                } else {
                    it++;
                }
            }
        }
        return ans;
    }
};