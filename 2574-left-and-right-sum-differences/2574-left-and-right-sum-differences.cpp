class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
    //Approach 1
    int n=nums.size();
    vector<int>ls;
    int l=0;
    for(int i=0;i<nums.size();i++){
        ls.push_back(l);
        l+=nums[i];
    }
    vector<int>rs(n);
int r=0;
    for(int i=n-1;i>=0;i--){
        rs[i]=r;
        r+=nums[i];


    }
    //
    vector<int>ans;

    for(int i=0;i<n;i++){
        ans.push_back(abs(ls[i]-rs[i]));
    }
return ans;
    }

};