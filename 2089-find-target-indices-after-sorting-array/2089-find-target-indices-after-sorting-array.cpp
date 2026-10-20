class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        
        // sort(nums.begin(),nums.end());
        // vector<int>ans;
        
        // for(int i=0;i<nums.size();i++){
           
        //     if(nums[i]==target){
                
        //         ans.push_back(i);

        //     }
           
        // }
        // return ans;

        //optimization - O(n) 
        vector<int>ans;
        int c=0;
        int smaller=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<target) smaller++;
            else if(nums[i]==target) c++;
        }

        if(smaller!=0){
            while(c){
                ans.push_back(smaller);
                smaller++;
                c--;
                
            }    
                }

                else {
                    int j=0;
                    while(c){
                        ans.push_back(j);
                        j++;
                        c--;
                    }
                }
                return ans;

    }
};