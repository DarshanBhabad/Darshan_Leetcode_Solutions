class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        
int n=nums.size();
        //most basic brute force using sliding window worst case tc is O(n2)+O(n);
        // we have to make sure or take care that it is fine if elemnt comes in same subarray multiple times ... just it should not be present in multiple subarrays of size k
    unordered_map<int,int>m;
    int j;
   for(int i=0;i<=n-k;i++){ //subarray 
   
     unordered_set<int> s; // make sure for current window we are fine with repeating elements no nned to increment
     for(int j = 0; j < k; j++) {
        s.insert(nums[i+j]);
    }
       for(auto x : s) {
        m[x]++;
    }
   }

int ans=-1; //all inputs willl be +ve so no problem 
   for(auto p:m){
    if(p.second==1) ans=max(ans,p.first);
   }
   return ans;
    }
};