class Solution {
public:
    int minMoves2(vector<int>& nums) {
        //it is a greedy problem we have to sort the array as we need to make all 
        // equal either by increment or decrement we have to sort and find middle element 
        // as it will be the closer to min and max elements so both needs minimum oprations to be equal to it
int n=nums.size();
// TC= n+logn
        sort(nums.begin(),nums.end());
        int mid=0+(n-0)/2; //middle index
        //int mide=nums[mid];
        int ans=0;
        //elemnts smaller than mid ele needs nums[mid]-nums[i]; +1 operations
        for(int i=0;i<mid;i++){
             ans+=nums[mid]-nums[i];
        }

        //elemnts greater than mid ele needs  ans+=nums[j]-nums[mid];; -1 operations
        for(int j=n-1;j>mid;j--){
            ans+=nums[j]-nums[mid];
        }
        return ans;
    }
};