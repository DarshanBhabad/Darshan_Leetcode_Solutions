class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Hash Table/sorting/ array TC=O(nlogn)  SC(O(n))
    //   unordered_map<int,int>m;
    //   int n=nums.size();
    //   for(int i=0;i<n;i++){
    //     m[nums[i]]++;
    //   }
    //    vector<pair<int,int>>v;
    //    for(auto s : m){
    //     v.push_back(s);
    //    }
    //    sort(v.begin(), v.end(), [](pair<int,int> &a, pair<int,int> &b) { //custorm comparator
    //      return a.second > b.second;   // descending order of frequency
    //  });
    //    vector<int> ans(k);

    //  for (int i = 0; i < k; i++) {
    //     ans[i] = v[i].first;
    //   }

    //   return ans;

      //APPROACH 2 
      // Hash Table / min heap / array 
      // min heap maintains min val of curr tree at root and we remove it provides stack operaations also 
      // TC=O(n) //no sorting so no logn SC= O(n)  
      // Heaps understanding Refer Problem 215

      unordered_map<int,int>m;
      int n=nums.size();
      for(int i=0;i<n;i++){
        m[nums[i]]++;
      }
      
      priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> q;
        // for min heap ...max heap has by default container and sorting logic only need data type 
        // NOTE : priority_queue with greater<pair<int,int>> compares pairs 
        // lexicographically : first if equal, then second  in case of pairs 
        // so we push fre 1st and then number
      for(auto s : m){
        q.push({s.second,s.first}); //{freq, number}
        if(q.size()>k){
            q.pop();  // if size gets bigger than k heap will pop smallest freq and rearrages itself
        }
      }
  vector<int>ans;
  while(!q.empty()){
    ans.push_back(q.top().second);  //here for q ... first is freq and second is number istdelf 
    q.pop();   // as top k elemnts can be in any order given in que 
    // as our logic will push [2,1] as top has min freq 2 for number 2 at root (top) instead of [1,2] 
    // if you need meaintain order in ans also then just reverse vector 
    // reverse()  //Time Complexity: O(k) Space Complexity: O(1)
  }

return ans;
    }
};