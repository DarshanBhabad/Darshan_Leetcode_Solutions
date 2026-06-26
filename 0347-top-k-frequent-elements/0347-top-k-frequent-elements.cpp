class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      unordered_map<int,int>m;
      int n=nums.size();
      for(int i=0;i<n;i++){
        m[nums[i]]++;
      }
       vector<pair<int,int>>v;
       for(auto k : m){
        v.push_back(k);
       }
       sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b) { //custorm comparator
         return a.second > b.second;   // descending order of frequency
     });
       vector<int> ans(k);

     for (int i = 0; i < k; i++) {
        ans[i] = v[i].first;
      }

      return ans;
    }
};