class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // all nums[i] are positive so we can use priority queue with maintaining size 2 
        // min heap : so that we pop minimum element 
        //Tc = O(1) + nlogn = nlogn 
        // for prod to be max elemnts should be maximum
        priority_queue<int,vector<int>,greater<int>>q;

        for(int i=0;i<nums.size();i++){
          
            q.push(nums[i]);
            if(q.size()>2){
                q.pop();
            }

            
        }
        
        int prod=1;
        while(!q.empty()){
            prod*=(q.top()-1);
            q.pop();
        }
    return prod;
    }
};