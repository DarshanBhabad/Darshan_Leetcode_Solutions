class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>s;
  vector<int>ans(n,-1);
        for(int i=0;i<2*n;i++){ //two passes 1st pass will find the possible next greaters remaining will be found in next pass
        int idx=i%n; //to keep valid indicies
        while(!s.empty() && nums[idx]>nums[s.top()]){ //next greater of stored s.top
            ans[s.top()]=nums[idx]; 
//            nums[s.top()] = 3
// nums[idx] = 4

// Since 4 > 3, 4 is the next greater element of 3, so we should pop 3 and set:
// ans[3] = 4;
//while because check for all indices in stack if current elemnt is greater or not
            s.pop();
        }
        

            if(i<n){ //each element will be pushed only once so only in first iteration not next cyclr to n
                s.push(i);
            }



        }
        return ans;
    }
};