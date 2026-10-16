class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(nums[i]);
        }
        for(int i=0;i<=n;i++){
            if(s.find(i)==s.end()) return i;
        }
        return 0;

        // 
    //     int n=nums.size();
    //    int sum=0;
    //    for(int i=0;i<n;i++)
    //    {
    //     sum+=nums[i];

    //    } 
    //    return n*(n+1)/2-sum;  total possible dum from 0 to n n*n+1/2 - our sum = elemnt
    }
};