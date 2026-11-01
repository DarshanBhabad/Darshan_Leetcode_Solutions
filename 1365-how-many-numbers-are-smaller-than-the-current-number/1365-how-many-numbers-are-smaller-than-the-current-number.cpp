class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        //tc=nlogn + n  ans sc= n
                vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        unordered_map<int, int> mp; //onlu first occurence

        for (int i = 0; i < sorted.size(); i++) {
            // Store only the first occurrence on sorted so
            // prv of that will be smaller than hi 
            if (mp.find(sorted[i]) == mp.end()) { //1st ocurrence 
                mp[sorted[i]] = i;  
            }
        }

        vector<int> ans;

        for (int x : nums) {
            ans.push_back(mp[x]);
        }

        return ans;

    }
};