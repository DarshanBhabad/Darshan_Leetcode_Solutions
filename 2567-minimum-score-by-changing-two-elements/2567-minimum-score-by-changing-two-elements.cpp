class Solution {
public:
    int minimizeSum(vector<int>& nums) {

        //we will keep min difference always 0;

//         We can always change two elements to the same value, making:
// low = 0
// Therefore, we only need to minimize high.

        // and change 2 number to maimum numberr so min always zero;
        
        // min size of array / nums is 3
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mindiff=0;// min doiff always 0;

        int maxdiff=INT_MAX;
        //maxdiff=maximum -minimum
        //3 cases to minimize the high or maxdiff so final score will be minimum

        //c1 change two smallest 
        // for maximum range we have to consider extrems only  middle elemnts wont matter as array is sorted 
        maxdiff=min(maxdiff,nums[n-1]-nums[2]);
        //c2 change smallest and largest to same ele ex 6,1 whetever
        maxdiff=min(maxdiff,nums[n-2]-nums[1]);
        // change 2 largest 
        maxdiff=min(maxdiff,nums[n-3]-nums[0]);




        
return maxdiff+mindiff;
    }
};