class Solution {
public:

 int maxSubarrayLength(vector<int>& nums, int k) {
// SLIDING WINDOW TC=O(n)
//We maintain a window [i...j] where every element occurs at most k times.
int n=nums.size();
 unordered_map<int,int>m; //store frequency
int ans=0;
int i=0; 
for(int j=0;j<n;j++){
    m[nums[j]]++;
    while(m[nums[j]]>k){
       m[nums[i]]--; // have to reduce count of ith ele as we are not considering it
       i++;


    }
   ans= max(ans,j-i+1);// j-i+1 toytal ele from i to j  also ans stores the maximum length so far
}
return ans;


// //GREEDY APPROACH but doesnt worl for all test case ex [1,2,4,4,3] k=1, output=2, expected=3; 
//TC=O(n^2) worst case chec an be called n times so n*n
// bool check( unordered_map<int,int>& m,int k){
    
//     for(auto p:m) {
//         if(p.second>k)return false;
//     }
//     return true;;
// }
//     int maxSubarrayLength(vector<int>& nums, int k) {
//     int n=nums.size();
//         unordered_map<int,int>m;
//         for(int i=0;i<n;i++){
//             m[nums[i]]++;

//         }
//        if(check(m,k)) return n;
//        int size=n;
//        int i=0,j=n-1;
//        while(i<j){
//         if(check(m,k))return size;
//         if(m[nums[i]]>=m[nums[j]]){
//             m[nums[i]]--;
//             i++;
           
//             size--;
//         }
//         else{
//              m[nums[j]]--;
//             j--;
           
//             size--;;
//         }
//        }
//         return size;
    }
};