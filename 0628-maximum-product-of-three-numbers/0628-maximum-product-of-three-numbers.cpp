class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        // The maximum product can either be from:
        // - The three largest numbers
        // - The two smallest numbers and the largest number
        int n=nums.size();
        int maxprod=INT_MIN;
        sort(nums.begin(),nums.end());
        maxprod=max(nums[n-1] * nums[n-2] * nums[n-3], nums[0] * nums[1] * nums[n-1]);
        return maxprod;



 //NOT WORKABLE: nums = [-100,-98,-1,2,3,4]  -ve int not handled well
//         //using priority queue (min heap of size 3) TC=nlogn
//         // product will be maximum for 3 max ele from the nums
//         priority_queue<int ,vector<int>, greater<int>>q;
//         for(int i=0;i<n;i++){
//             if(nums[i]<0)q.push(-nums[i]); // we have to make sure if there are more than 2 -ve ele in array only 2 smallest (i.e in -ve sense -100 <-1) in queue
//             else q.push(nums[i]);
//             if(q.size()>3) q.pop();

//         }

//         int prod=1;
//   while(!q.empty()){
//     prod=prod*q.top();
//     q.pop();
//   }
//   return prod;
    }
};