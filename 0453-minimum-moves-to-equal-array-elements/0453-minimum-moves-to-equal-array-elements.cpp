class Solution {
public:
    int minMoves(vector<int>& nums) {
        //as our move provides only option to incremnt and that to by 1 
        //  we use opposite sense decremening elements to min elemnt 
        //becoz if we increment upto max these willl happen [1,2,3]  =>  [2,3,3] // so her we have to increment max also as -> onr move increent n - 1 elements simultaneously.
// onr move increent n - 1 elements simultaneously.
//there can be duplicate elements 
int n=nums.size();
        int mini=0;
        for(int i=1;i<n;i++){
             if(nums[i]<nums[mini]) mini=i;
        }
int ans=0;
        for(int i=0;i<n;i++){
             if(i==mini) continue;
             ans+=nums[i]-nums[mini]; 
        }
        return ans;
    }
};