class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
 // now from simple observation all middle elemnts has to be in different subarrays if window size is greater than 1

 //TC=O(n)

 int n=nums.size();
int ans=-1;
 if(k==1) { //window size 1
      unordered_map<int,int> m;

    for(int x : nums)
        m[x]++;

    for(auto p : m) {
        if(p.second == 1) // ele which appeared only once
            ans = max(ans, p.first);
    }

    return ans;
 }
 else if(k == n) { //single window
    for(int x : nums)
        ans = max(ans, x);
    return ans;
}

 else{
    //ans has tobe from 1st and last element
    //just make sure they don't found in middle i.e betn(0,n-1) 
    bool s=false;
    bool e=false;
    for(int i=0;i<n;i++){
        if(nums[i]==nums[0]&&i!=0) s=true;
        if(nums[i]==nums[n-1]&&i!=n-1) e=true;
    }
    if(s&&e)return ans; //i.e -1
    else if(!s && e) return nums[0];
    else if(s && !e) return nums[n-1];
    else return max(nums[0],nums[n-1]);
 } 

        
// int n=nums.size();
//         //most basic brute force using sliding window worst case tc is O(n2)+O(n);
//         // we have to make sure or take care that it is fine if elemnt comes in same subarray multiple times ... just it should not be present in multiple subarrays of size k
//     unordered_map<int,int>m;
//     int j;
//    for(int i=0;i<=n-k;i++){ //subarray 
   
//      unordered_set<int> s; // make sure for current window we are fine with repeating elements no nned to increment
//      for(int j = 0; j < k; j++) {
//         s.insert(nums[i+j]);
//     }
//        for(auto x : s) {
//         m[x]++;
//     }
//    }

// int ans=-1; //all inputs willl be +ve so no problem 
//    for(auto p:m){
//     if(p.second==1) ans=max(ans,p.first);
//    }
//    return ans;

    }
};